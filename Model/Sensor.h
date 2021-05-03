#ifndef SENSOR_H
#define SENSOR_H
class Sensor {

	private:
		int id;
		float latitude;
		float longitude;
		User owner;
		list readings;

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

		list getReadings();

		void setReadings(list readings);
};

#endif
