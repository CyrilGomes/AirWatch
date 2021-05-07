#include "ApplicationServices.h"
#include "../Database/DBManager.h"

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
	// TODO - implement ApplicationServices::getCleanerContribution
	throw "Not yet implemented";
}

void ApplicationServices::importData() {
	DBManager::setDirectory("Dataset/");
	DBManager::importCentralAndLocalData();
}

void ApplicationServices::saveData() {
	DBManager::saveLocalData();
}
