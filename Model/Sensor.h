#ifndef SENSOR_H
#define SENSOR_H

class Individual;
#include <map>
#include "Reading.h"
#include "Date.h"
#include "ReliabilityFlag.h"

class Sensor {

	private:
		int id;
		float latitude;
		float longitude;
		ReliabilityFlag reliabilityFlag;
		Individual* owner;
		map<Date, Reading*> readings;

	public:
		Sensor(int id, float latitude, float longitude);
		~Sensor();
		int getId();
		void setId(int id);
		float getLatitude();
		void setLatitude(float latitude);
		float getLongitude();
		void setLongitude(float longitude);
		ReliabilityFlag getReliabilityFlag();
		void setReliabilityFlag(ReliabilityFlag reliabilityFlag);
		Individual* getOwner();
		void setOwner(Individual* owner);
		map<Date, Reading*> getReadings();
		void addReading(Reading* reading);

};

#endif
