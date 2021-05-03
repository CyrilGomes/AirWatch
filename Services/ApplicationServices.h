#ifndef APPLICATIONSERVICES_H
#define APPLICATIONSERVICES_H

class ApplicationServices {


	public:
		ReliabilityFlag checkSensorsReliabilities(Date uTBegin, Date uTEnd);

		void flagSensor(int uSensorID, bool uFlag);

		list compareSensorSimilarities(int uSensorID, Date uTBegin, Date uTEnd);

		float getAreaAirQuality(float uLat, float uLon, float uRad, Date uTBegin, Date uTEnd);

		float getPunctualAirQuality(float uLat, float uLon, Date uTBegin, Date uTEnd);

		Array getCleanerContribution(int uCleanerID);

		void importData();
};

#endif
