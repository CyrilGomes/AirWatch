#ifndef SENSOR_H
#define SENSOR_H

namespace Model {
	class Sensor {

	private:
		int id;
		float latitude;
		float longitude;
		Model::User owner;
		List readings;

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

		List getReadings();

		void setReadings(List readings);
	};
}

#endif
