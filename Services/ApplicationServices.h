#ifndef APPLICATIONSERVICES_H
#define APPLICATIONSERVICES_H

#include <list>
#include "../Model/Date.h"
#include "../Model/ReliabilityFlag.h"
#include "../Model/Sensor.h"
using namespace std;

class ApplicationServices {

	public:
		ReliabilityFlag checkSensorsReliabilities(Date uTBegin, Date uTEnd);
		void flagSensor(int uSensorID, bool uFlag);
		list<Sensor> compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd);
		float getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd);
		float getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd);
		float* getCleanerContribution(int uCleanerID);
		void importData();

};

#endif
