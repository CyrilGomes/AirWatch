#ifndef SENSOR_H
#define SENSOR_H

#include <list>
#include "Reading.h"

using namespace std;

namespace Model {
	class Sensor {

	private:
		int id;
		float latitude;
		float longitude;
		User owner;
		list<Model::Reading> readings;

	public:
		Sensor(int id, float latitude, float longitude);

		int getId();

		void setId(int id);

		float getLatitude();

		void setLatitude(float latitude);

		float getLongitude();

		void setLongitude(float longitude);

		Model::User getOwner();

		void setOwner(Model::User owner);

		list<Model::Reading> getReadings();

		void setReadings(list<Model::Reading> readings);
	};
}

#endif
