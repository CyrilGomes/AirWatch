#include <math.h>
#include <bits/stdc++.h>
#include "ApplicationServices.h"
#include "../Database/DBManager.h"
#include "../Model/ApplicationData.h"
#include "../Model/ReliabilityFlag.h"
#include "Exceptions.h"

/* -------------------------------------------------------------------------- */
/* METHOD: checkSensorsReliabilities() -------------------------------------- */
/* -------------------------------------------------------------------------- */
vector<Sensor*> ApplicationServices::checkSensorsReliabilities(Date uTBegin, Date uTEnd)
{
	throw "Not yet implemented";
}

/* -------------------------------------------------------------------------- */
/* METHOD: flagSensor() ----------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void ApplicationServices::flagSensor(int uSensorID, bool uFlag)
{
	throw "Not yet implemented";
}

/* -------------------------------------------------------------------------- */
/* METHOD: compareSensorSimilarities() -------------------------------------- */
/* Returns a list of sensors whose data is similar to the given one (in the - */
/* given timespan) ---------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
vector<Sensor*> ApplicationServices::compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd)
{
	//Vars
	vector<Sensor*> similarSensors;
	Sensor* sensor;
	float threshold = 0.1;

	// Fetch data
	ApplicationData *applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor *> sensorList = applicationData->getSensorList();
	// If no sensor is found, throw error
	if (uSensorID >= (int)sensorList.size()) {
		throw UnknownSensorException();
	}
	sensor = sensorList[uSensorID];

	// Check that readings aren't empty
	map<Date, Reading *> readings = sensor->getReadings();
	if (readings.empty()) {
		throw EmptyReadingsException();
	}

	// Check that dates are in database bounds
	Date minDate = readings.begin()->first;
	Date maxDate = readings.rbegin()->first;
	if (uTBegin < minDate || maxDate < uTEnd) {
		throw TimeSpanOutOfBoundException();
	}

	// Loop through its readings starting from uTBegin to uTEnd
	map<Date, Reading *>::iterator readingsBegin = readings.lower_bound(uTBegin);
	map<Date, Reading *>::iterator readingsEnd = readings.upper_bound(uTEnd);

	for (pair<int, Sensor *> ite : sensorList) {
		float diffAverage = 0;
		int i = 0;
		Sensor *os = ite.second;
		if (os->getId() == uSensorID)
			continue;

		int atmo1 = 0;
		int atmo2 = 0;
		map<Date, Reading *> osReadings = os->getReadings();
		for (auto r = readingsBegin; r != readingsEnd; ++r) {
			Reading *reading1 = r->second;
			Reading *reading2 = osReadings[r->first];
			// Compute average of differences in ATMO scores
			atmo1 = reading1->atmo();
			atmo2 = reading2->atmo();
			diffAverage = diffAverage + (atmo1 - atmo2);
			i++;
		}

		diffAverage = abs(diffAverage / (float)i);
		if (diffAverage < threshold) {
			similarSensors.push_back(os);
		}
	}

	// Save the data (in case some individual points were updated)
	saveData();

	// Returns similar Sensors
	return similarSensors;
}

/* -------------------------------------------------------------------------- */
/* METHOD: getAreaAirQuality() ---------------------------------------------- */
/* -------------------------------------------------------------------------- */
float ApplicationServices::getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd)
{
	throw "Not yet implemented";
}

/* -------------------------------------------------------------------------- */
/* METHOD: getPunctualAirQuality() ------------------------------------------ */
/* Returns the ATMO index at the given location (in the given timespan) ----- */
/* -------------------------------------------------------------------------- */
float ApplicationServices::getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd)
{
	// Vars
	float average = 0;
	float i = 0;
	int j = 0;
	int distThreshold = 120000;
	int maxPoints = 6;

	// Fetch data
	ApplicationData *applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor *> sensorList = applicationData->getSensorList();

	// Put all sensors in a vector and sort them based by distance to given position
	vector<Sensor *> sortedSensorsList;
	for (pair<int, Sensor *> i : sensorList) {
		sortedSensorsList.push_back(i.second);
	}
	sort(sortedSensorsList.begin(), sortedSensorsList.end(), [&](const Sensor *s1, const Sensor *s2) -> bool {
		 float d1 = ApplicationServices::distance(
			 s1->getLatitude(), s1->getLongitude(),
			 uLat, uLon
		 );
		 float d2 = ApplicationServices::distance(
			 s2->getLatitude(), s2->getLongitude(),
			 uLat, uLon
		 );
		 return d1 < d2;
	 });

	// Loop through sorted sensor list
	for (Sensor *s : sortedSensorsList) {
		// Skip if sensor is unreliable
		if (s->getReliabilityFlag() == ReliabilityFlag::unreliable) {
			continue;
		}
		
		// Get distance to given position
		float dist = ApplicationServices::distance(s->getLatitude(), s->getLongitude(), uLat, uLon);
		
		// If the sensor isn't too far away...
		if (dist <= distThreshold) {
			// Calculate the weight factor based on distance
			float weight = 1000 / pow(max(dist, 0.1f), 2);

			j += 1;
			// Break out of loop if we already used enough sensors
			if (j > maxPoints) {
				break;
			}
			
			// Check that readings aren't empty
			map<Date, Reading *> readings = s->getReadings();
			if (readings.empty()) {
				continue;
			}
			
			// Check that dates are in database bounds
			Date minDate = readings.begin()->first;
			Date maxDate = readings.rbegin()->first;
			if (uTBegin < minDate || maxDate < uTEnd) {
				continue;
			}

			// Loop through its readings starting from uTBegin to uTEnd
			map<Date, Reading *>::iterator readingsBegin = readings.lower_bound(uTBegin);
			map<Date, Reading *>::iterator readingsEnd = readings.upper_bound(uTEnd);
			for_each(readingsBegin, readingsEnd, [&](pair<Date, Reading *> r) {
				 Reading *reading = r.second;
				 // Compute average with weight factor
				 average += reading->atmo() * weight;
				 i += weight;
			 });
		}
	}

	// Average ATMO levels out
	// If more than 2 sensors have been used...
	if (j > 1) {
		// If readings have been used...
		if (i > 0) {
			average /= i;
		}
		// If no readings have been used, the timestamps are out of scope
		else {
			throw TimeSpanOutOfBoundException();
		}
	}
	// If less than 2 sensors have been used, the location is too far away
	else {
		throw LocationTooFarAwayException();
	}

	// Save the data (in case some individual points were updated)
	saveData();

	// Return data
	return average;
}

/* -------------------------------------------------------------------------- */
/* METHOD: getCleanerContribution() ----------------------------------------- */
/* Returns the radius of effect and efficiency of the given cleaner --------- */
/* -------------------------------------------------------------------------- */
pair<float, float> ApplicationServices::getCleanerContribution(int uCleanerID)
{
	// Vars
	float atmoThreshold = 2;
	float distThreshold = 600000;
	float atmoAverageBeforeStop = 0;
	float atmoAverageAtStop = 0;
	float rad = 0;
	float improvement = 0;
	int count = 0;

	// Fetch data
	ApplicationData *applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor *> sensorList = applicationData->getSensorList();
	unordered_map<int, Cleaner *> cleanerList = applicationData->getCleanerList();
	// If no cleaner is found, return negative floats as error codes
	if (uCleanerID >= (int)cleanerList.size()) {
		throw UnknownCleanerException();
	}
	Cleaner *cleaner = cleanerList[uCleanerID];
	float cleanerLat = cleaner->getLatitude();
	float cleanerLon = cleaner->getLongitude();
	Date cleanerStartDate = cleaner->getStartDate();
	Date cleanerStopDate = cleaner->getStopDate();

	// Put all sensors in a vector and sort them based on distance to cleaner
	vector<Sensor *> sortedSensorsList;
	for (pair<int, Sensor *> i : sensorList) {
		sortedSensorsList.push_back(i.second);
	}
	sort(sortedSensorsList.begin(), sortedSensorsList.end(), [&](const Sensor *s1, const Sensor *s2) -> bool {
		 float d1 = ApplicationServices::distance(
			 s1->getLatitude(), s1->getLongitude(),
			 cleanerLat, cleanerLon);
		 float d2 = ApplicationServices::distance(
			 s2->getLatitude(), s2->getLongitude(),
			 cleanerLat, cleanerLon);
		 return d1 < d2;
	 });

	int oCount = 0;
	// Loop through sorted sensor list
	for (Sensor *i : sortedSensorsList) {
		// Skip if sensor is unreliable
		if (i->getReliabilityFlag() == ReliabilityFlag::unreliable) {
			continue;
		}

		//Checks if the map is empty and if the time period is in bounds
		map<Date, Reading *> readings = i->getReadings();
		if (readings.empty()) {
			continue;
		}

		// Check that dates are in database bounds
		Date minDate = readings.begin()->first;
		Date maxDate = readings.rbegin()->first;
		if (cleanerStartDate < minDate || maxDate < cleanerStopDate || maxDate == cleanerStopDate) {
			continue;
		}

		// Get their atmo before the end and at the end of the cleaner's action
		int atmoAtStart = readings.lower_bound(cleanerStartDate)->second->atmo();
		int atmoBeforeStop = prev(readings.upper_bound(cleanerStopDate))->second->atmo();
		int atmoAtStop = readings.upper_bound(cleanerStopDate)->second->atmo();

		// Get distance between sensor and cleaner
		float dist = ApplicationServices::distance(
			i->getLatitude(), i->getLongitude(),
			cleanerLat, cleanerLon
		);
			
		// Dermine if there's another cleaner closer to that sensor
		bool foundCloser = false;

		for (pair<int, Cleaner*> j : cleanerList) {
			float oDist = ApplicationServices::distance(
				i->getLatitude(), i->getLongitude(),
				j.second->getLatitude(), j.second->getLongitude());
			if (oDist < dist) {
				foundCloser = true;
				break;
			}
		}

		// Skip sensor if it's closer to another cleaner
		if (foundCloser) {
			continue;
		}

		// If no improvement has been found for a long distance, stop search
		if (dist - rad > distThreshold && count == oCount && count > 0) {
			break;
		}

		// If there's a significant difference of ATMO at that point at the end and right after the cleaner's action,
		// Mark that as an improvement
		if (atmoAtStop - atmoBeforeStop >= atmoThreshold) {
			// Save the radius
			rad = dist;
			// Save the ATMO levels
			atmoAverageBeforeStop += atmoBeforeStop;
			atmoAverageAtStop += atmoAtStop;
			// Save the improvement counter
			oCount = count;
			count++;
		}
	}

	// Average ATMO levels out
	if (count != 0) {
		atmoAverageBeforeStop /= count;
		atmoAverageAtStop /= count;
		improvement = atmoAverageAtStop - atmoAverageBeforeStop;
	}

	// Save the data (in case some individual points were updated)
	saveData();

	// Return data
	return make_pair(rad, improvement);
}

/* -------------------------------------------------------------------------- */
/* METHOD: importData() ----------------------------------------------------- */
/* Calls the DBManager to import the csv data into the application ---------- */
/* -------------------------------------------------------------------------- */
void ApplicationServices::importData(string dataDirectory)
{
	DBManager::setDirectory(dataDirectory);
	DBManager::importCentralAndLocalData();
}

/* -------------------------------------------------------------------------- */
/* METHOD: saveData() ------------------------------------------------------- */
/* Calls the DBManager to save the application's data into the .csv files --- */
/* -------------------------------------------------------------------------- */
void ApplicationServices::saveData()
{
	DBManager::saveLocalData();
}

/* -------------------------------------------------------------------------- */
/* METHOD: cleanup() -------------------------------------------------------- */
/* Destroys the application data instance, initiating the cleanup procedure - */
/* -------------------------------------------------------------------------- */
void ApplicationServices::cleanup()
{
	delete ApplicationData::getInstance();
}

/* -------------------------------------------------------------------------- */
/* METHOD: distance() ------------------------------------------------------- */
/* Returns the distance (in meters) between pairs of lat/lon coordinates ---- */
/* -------------------------------------------------------------------------- */
float ApplicationServices::distance(float lat1, float lon1, float lat2, float lon2) 
{
    float earthRadius = 6378137.0;
    float lat1_rad = lat1 * M_PI/180.0; float lon1_rad = lon1 * M_PI/180.0;
    float lat2_rad = lat2 * M_PI/180.0; float lon2_rad = lon2 * M_PI/180.0;
    return acos(sin(lat1_rad)*sin(lat2_rad)+cos(lat1_rad)*cos(lat2_rad)*cos(lon2_rad-lon1_rad))*earthRadius;
}
