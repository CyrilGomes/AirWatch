#include "ApplicationServices.h"

ReliabilityFlag ApplicationServices::checkSensorsReliabilities(Date uTBegin, Date uTEnd) const {
	// TODO - implement ApplicationServices::checkSensorsReliabilities
	throw "Not yet implemented";
}

void ApplicationServices::flagSensor(int uSensorID, bool uFlag) const {
	/*if (!uFlag) {
		if (sensor->owner != nullptr) {
			sensor->owner->setReliabilityFlag(reliabilityFlag);
		}
	}*/
	throw "Not yet implemented";
}

vector<Sensor*> ApplicationServices::compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd) const {
	// TODO - implement ApplicationServices::compareSensorSimilarities
	throw "Not yet implemented";
}

float ApplicationServices::getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd) const {
	// TODO - implement ApplicationServices::getAreaAirQuality
	throw "Not yet implemented";
}

float ApplicationServices::getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd) const {
	// TODO - implement ApplicationServices::getPunctualAirQuality
	throw "Not yet implemented";
}

pair<float, float> ApplicationServices::getCleanerContribution(int uCleanerID) const {
	// TODO - implement ApplicationServices::getCleanerContribution
	throw "Not yet implemented";
}

void ApplicationServices::importData() const {
	// TODO - implement ApplicationServices::importData
	throw "Not yet implemented";
}
