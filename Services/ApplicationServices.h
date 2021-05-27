#ifndef APPLICATIONSERVICES_H
#define APPLICATIONSERVICES_H

#include <vector>
#include "../Model/Date.h"
#include "../Model/ReliabilityFlag.h"
#include "../Model/Sensor.h"
using namespace std;

class ApplicationServices {

	public:
		static ReliabilityFlag checkSensorsReliabilities(Date uTBegin, Date uTEnd);
		static void flagSensor(int uSensorID, bool uFlag);
		static vector<Sensor*> compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd);
		static float getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd);
		static float getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd);
		static pair<float, float> getCleanerContribution(int uCleanerID);
		static void importData(string dataDirectory);
		static void saveData();
		static void cleanup();

};

#endif
