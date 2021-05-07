#ifndef APPLICATIONSERVICES_H
#define APPLICATIONSERVICES_H

#include <vector>
#include "../Model/Date.h"
#include "../Model/ReliabilityFlag.h"
#include "../Model/Sensor.h"
using namespace std;

class ApplicationServices {

	public:
		ReliabilityFlag checkSensorsReliabilities(Date uTBegin, Date uTEnd) const;
		void flagSensor(int uSensorID, bool uFlag) const;
		vector<Sensor*> compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd) const;
		float getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd) const;
		float getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd) const;
		pair<float, float> getCleanerContribution(int uCleanerID) const;
		void importData() const;

};

#endif
