#include <math.h>
#include <bits/stdc++.h>
#include "ApplicationServices.h"
#include "../Database/DBManager.h"
#include "../Model/ApplicationData.h"
#include "../Model/ReliabilityFlag.h"

ReliabilityFlag ApplicationServices::checkSensorsReliabilities(Date uTBegin, Date uTEnd)
{
	throw "Not yet implemented";
}

void ApplicationServices::flagSensor(int uSensorID, bool uFlag)
{
	throw "Not yet implemented";
}

vector<Sensor*> ApplicationServices::compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd)
{

	//Vars
	vector<Sensor*> similarSensors;
	Sensor *sensor;
	
	
	float threshold = 0.1;

	// Fetch data
	ApplicationData *applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor *> sensorList = applicationData->getSensorList();
	// If no sensor is found, throw error
	if (uSensorID >= sensorList.size()) {
		throw "(!) The entered Sensor ID is unknown";
	}	
	sensor = sensorList[uSensorID];

	// Loop through its readings starting from uTBegin to uTEnd
	map<Date, Reading *> readings = sensor->getReadings();
	map<Date, Reading *>::iterator readingsBegin = readings.lower_bound(uTBegin);
	map<Date, Reading *>::iterator readingsEnd = readings.upper_bound(uTEnd);

	for (pair<int, Sensor *> ite : sensorList)
	{
		
		float diffAverage = 0;
		int i = 0;
		Sensor *os = ite.second;
		if (os->getId() == uSensorID)
			continue;

		map<Date, Reading *> osReadings = os->getReadings();

		int atmo1 = 0;
		int atmo2 = 0;
		for (auto r = readingsBegin; r != readingsEnd; ++r)
		{

			Reading *reading1 = r->second;
			Reading *reading2 = osReadings[r->first];

			// Compute average of differences in ATMO scores
			atmo1 = reading1->atmo();
			atmo2 = reading2->atmo();

			diffAverage = diffAverage + (atmo1 - atmo2);

			i++;
		}

		diffAverage = abs(diffAverage / (float)i);
		//cout << os->getId()<<" " <<diffAverage << endl;
		if (diffAverage < threshold)
		{
			similarSensors.push_back(os);
		}
	}

#ifndef TEST
	// Save the data (in case some individual points were updated)
	saveData();
#endif

	// Returns similar Sensors
	return similarSensors;
}

float ApplicationServices::getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd)
{
	throw "Not yet implemented";
}

float ApplicationServices::getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd)
{

	// Vars
	float average = 0;
	float i = 0;
	int j = 0;
	int distThreshold = 100000;
	int maxPoints = 6;

	// Fetch data
	ApplicationData *applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor *> sensorList = applicationData->getSensorList();

	// Put all sensors in a vector and sort them based by distance to given position
	vector<Sensor *> sortedSensorsList;
	for (pair<int, Sensor *> i : sensorList)
	{
		sortedSensorsList.push_back(i.second);
	}
	sort(sortedSensorsList.begin(), sortedSensorsList.end(), [&](const Sensor *s1, const Sensor *s2) -> bool {
		float d1 = ApplicationData::distance(
			s1->getLatitude(), s1->getLongitude(),
			uLat, uLon);
		float d2 = ApplicationData::distance(
			s2->getLatitude(), s2->getLongitude(),
			uLat, uLon);
		return d1 < d2;
	});

	// Loop through sorted sensor list
	for (Sensor *s : sortedSensorsList)
	{
		// Skip if sensor is unreliable
		if (s->getReliabilityFlag() == ReliabilityFlag::unreliable)
		{
			continue;
		}
		// Get distance to given position
		float dist = ApplicationData::distance(s->getLatitude(), s->getLongitude(), uLat, uLon);
		// If the sensor isn't too far away...
		if (dist <= distThreshold)
		{
			// Calculate the weight factor based on distance
			float weight = 1000 / pow(max(dist, 0.1f), 2);
			// Loop through its readings starting from uTBegin to uTEnd
			map<Date, Reading *> readings = s->getReadings();
			map<Date, Reading *>::iterator readingsBegin = readings.lower_bound(uTBegin);
			map<Date, Reading *>::iterator readingsEnd = readings.upper_bound(uTEnd);
			for_each(readingsBegin, readingsEnd, [&](pair<Date, Reading *> r) {
				Reading *reading = r.second;
				// Compute average with weight factor
				average += reading->atmo() * weight;
				i += weight;
			});
			j += 1;
			// Break out of loop if we already used enough sensors
			if (j > maxPoints)
			{
				break;
			}
		}
	}

	// Average ATMO levels out
	// If more than 2 sensors have been used...
	if (j > 1)
	{
		// If readings have been used...
		if (i > 0)
		{
			average /= i;
		}
		// If no readings have been used, the timestamps are out of scope
		else
		{
			throw "(!) The time period you entered is not in the scope of the database";
		}
	}
	// If less than 2 sensors have been used, the location is too far away
	else
	{
		throw "(!) The entered location is too far away from any sensors";
	}

#ifndef TEST
	// Save the data (in case some individual points were updated)
	saveData();
#endif

	// Return data
	return average;
}

pair<float, float> ApplicationServices::getCleanerContribution(int uCleanerID)
{

	
	// Vars
	float atmoThreshold = 2;
	float distThreshold = 50000;
	float atmoAverageAtStart = 0;
	float atmoAverageAtStop = 0;
	float rad = 0;
	float improvement = 0;
	int count = 0;

	// Fetch data
	ApplicationData *applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor *> sensorList = applicationData->getSensorList();
	unordered_map<int, Cleaner *> cleanerList = applicationData->getCleanerList();
	// If no cleaner is found, return negative floats as error codes
	if (uCleanerID >= cleanerList.size())
	{
		throw "(!) The entered Cleaner ID is unknown";
	}
	Cleaner *cleaner = cleanerList[uCleanerID];
	float cleanerLat = cleaner->getLatitude();
	float cleanerLon = cleaner->getLongitude();
	Date cleanerStartDate = cleaner->getStartDate();
	Date cleanerStopDate = cleaner->getStopDate();
	
	// Put all sensors in a vector and sort them based on distance to cleaner
	vector<Sensor *> sortedSensorsList;
	for (pair<int, Sensor *> i : sensorList)
	{
		sortedSensorsList.push_back(i.second);
	}
	sort(sortedSensorsList.begin(), sortedSensorsList.end(), [&](const Sensor *s1, const Sensor *s2) -> bool {
		float d1 = ApplicationData::distance(
			s1->getLatitude(), s1->getLongitude(),
			cleanerLat, cleanerLon);
		float d2 = ApplicationData::distance(
			s2->getLatitude(), s2->getLongitude(),
			cleanerLat, cleanerLon);
		return d1 < d2;
	});

	int oCount = 0;
	// Loop through sorted sensor list
	for (Sensor *i : sortedSensorsList)
	{
		// Skip if sensor is unreliable
		if (i->getReliabilityFlag() == ReliabilityFlag::unreliable)
		{
			continue;
		}
		
		// Get their atmo at the start and at the end of the cleaner's action
		map<Date, Reading *> readings = i->getReadings();
		int atmoAtStart = readings.lower_bound(cleanerStartDate)->second->atmo();
		int atmoAtStop = readings.upper_bound(cleanerStopDate)->second->atmo();
		
		
		// Get distance between sensor and cleaner
		float dist = ApplicationData::distance(
			i->getLatitude(), i->getLongitude(),
			cleanerLat, cleanerLon);
		// Dermine if there's another cleaner closer to that sensor
		bool foundCloser = false;
		
		for (pair<int, Cleaner *> j : cleanerList)
		{
			float oDist = ApplicationData::distance(
				i->getLatitude(), i->getLongitude(),
				j.second->getLatitude(), j.second->getLongitude());
			if (oDist < dist)
			{
				foundCloser = true;
				break;
			}
		}
		
		// Skip sensor if it's closer to another cleaner
		if (foundCloser)
		{
			continue;
		}
		
		// If no improvement has been found for a long distance, stop search
		if (dist - rad > distThreshold && count == oCount && count > 0)
		{
			break;
		}
		
		// If there's a significant difference of ATMO at that point before and after the cleaner's action,
		// Mark that as an improvement
		if (atmoAtStop - atmoAtStart > atmoThreshold)
		{
			// Save the radius
			rad = dist;
			// Save the ATMO levels
			atmoAverageAtStart += atmoAtStart;
			atmoAverageAtStop += atmoAtStop;
			// Save the improvement counter
			oCount = count;
			count++;
		}
		
	}

	// Average ATMO levels out
	if (count != 0)
	{
		atmoAverageAtStart /= count;
		atmoAverageAtStop /= count;
		improvement = atmoAverageAtStop - atmoAverageAtStart;
	}

#ifndef TEST
	// Save the data (in case some individual points were updated)
	saveData();
#endif

	// Return data
	return make_pair(rad, improvement);
}

void ApplicationServices::importData(string dataDirectory)
{
	DBManager::setDirectory(dataDirectory);
	DBManager::importCentralAndLocalData();
}

void ApplicationServices::saveData()
{
	DBManager::saveLocalData();
}

void ApplicationServices::cleanup()
{
	delete ApplicationData::getInstance();
}
