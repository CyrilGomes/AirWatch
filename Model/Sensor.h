#ifndef SENSOR_H
#define SENSOR_H

#include <list>
#include "Reading.h"
#include "User.h"
using namespace std;


class Sensor
{

private:
	int id;
	float latitude;
	float longitude;
	User owner;
	list<Reading> readings;

public:
	Sensor(int id, float latitude, float longitude);

	int getId();

	void setId(int id);

	float getLatitude();

	void setLatitude(float latitude);

	float getLongitude();

	void setLongitude(float longitude);

	User getOwner();

	void setOwner(User owner);

	list<Reading> getReadings();

	void setReadings(list<Reading> readings);
};

#endif
