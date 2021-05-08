#include <bits/stdc++.h>
#include "ApplicationServices.h"
#include "../Database/DBManager.h"
#include "../Model/ApplicationData.h"

ReliabilityFlag ApplicationServices::checkSensorsReliabilities(Date uTBegin, Date uTEnd) {
	throw "Not yet implemented";
}

void ApplicationServices::flagSensor(int uSensorID, bool uFlag) {
	throw "Not yet implemented";
}

vector<Sensor*> ApplicationServices::compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd) {
	// TODO - implement ApplicationServices::compareSensorSimilarities
	throw "Not yet implemented";
}

float ApplicationServices::getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd) {
	throw "Not yet implemented";
}

float ApplicationServices::getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd) {
	// TODO - implement ApplicationServices::getPunctualAirQuality
	throw "Not yet implemented";
}

pair<float, float> ApplicationServices::getCleanerContribution(int uCleanerID) {

	// Vars
	float atmoThreshold = 2;
	float distThreshold = 50000;
	float atmoAverageAtStart = 0;
	float atmoAverageAtStop = 0;
	float rad = 0;
	float improvement = 0;
	int count = 0;

	// Fetch data
	ApplicationData* applicationData = ApplicationData::getInstance();
	unordered_map<int, Sensor*> sensorList = applicationData->getSensorList();
	unordered_map<int, Cleaner*> cleanerList = applicationData->getCleanerList();
	Cleaner* cleaner = cleanerList[uCleanerID];
	float cleanerLat = cleaner->getLatitude();
	float cleanerLon = cleaner->getLongitude();
	Date cleanerStartDate = cleaner->getStartDate();
	Date cleanerStopDate = cleaner->getStopDate();

	// If no cleaner is found, return negative floats as error codes
	if (cleaner == nullptr) {
		return make_pair(-1.0, -1.0);
	}

	// Put all sensors in a vector and sort them based by distance to cleaner
    vector<Sensor*> sortedSensorsList;
	for (pair<int, Sensor*> i : sensorList) {
		sortedSensorsList.push_back(i.second);
	}
	sort(sortedSensorsList.begin(), sortedSensorsList.end(), [&](const Sensor* s1, const Sensor* s2) -> bool {
		float d1 = ApplicationData::distance(
			s1->getLatitude(), s1->getLongitude(),
			cleanerLat, cleanerLon
		);
		float d2 = ApplicationData::distance(
			s2->getLatitude(), s2->getLongitude(),
			cleanerLat, cleanerLon
		);
		return d1 < d2;
	});

	int oCount = 0;
	// Loop through sorted sensor list
	for (Sensor* i : sortedSensorsList) {
		// Get their atmo at the start and at the end of the cleaner's action
		map<Date, Reading*> readings = i->getReadings();
		int atmoAtStart = readings.lower_bound(cleanerStartDate)->second->atmo();
		int atmoAtStop = readings.upper_bound(cleanerStopDate)->second->atmo();
		// Get distance between sensor and cleaner
		float dist = ApplicationData::distance(
			i->getLatitude(), i->getLongitude(),
			cleanerLat, cleanerLon
		);
		// Dermine if there's another cleaner closer to that sensor
		bool foundCloser = false;
		for (pair<int, Cleaner*> j : cleanerList) {
			float oDist = ApplicationData::distance(
				i->getLatitude(), i->getLongitude(),
				j.second->getLatitude(), j.second->getLongitude()
			);
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
		// If there's a significant difference of ATMO at that point before and after the cleaner's action,
		// Mark that as an improvement
		if (atmoAtStop - atmoAtStart > atmoThreshold) {
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
	if (count != 0) {
		atmoAverageAtStart /= count;
		atmoAverageAtStop /= count;
		improvement = atmoAverageAtStop - atmoAverageAtStart;
	}

	// Return data
	return make_pair(rad, improvement);

}

void ApplicationServices::importData() {
	DBManager::setDirectory("Dataset/");
	DBManager::importCentralAndLocalData();
}

void ApplicationServices::saveData() {
	DBManager::saveLocalData();
}
