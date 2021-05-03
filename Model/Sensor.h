#ifndef SENSOR_H
#define SENSOR_H

class Individual;
#include <list>
#include "Reading.h"

class Sensor {

	private:
		int id;
		float latitude;
		float longitude;
		Individual* owner;
		list<Reading> readings;

	public:
		Sensor(int id, float latitude, float longitude);
		int getId();
		void setId(int id);
		float getLatitude();
		void setLatitude(float latitude);
		float getLongitude();
		void setLongitude(float longitude);
		Individual* getOwner();
		void setOwner(Individual* owner);
		list<Reading> getReadings();
		void setReadings(list<Reading> readings);

};

#endif
