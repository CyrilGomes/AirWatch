#ifndef SENSOR_H
#define SENSOR_H

class Individual;
#include <map>
#include "Reading.h"
#include "Date.h"
#include "ReliabilityFlag.h"

/* -------------------------------------------------------------------------- */
/* SENSOR ------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
class Sensor {

	private:
		int id;
		float latitude;
		float longitude;
		ReliabilityFlag reliabilityFlag;
		Individual* owner;
		map<Date, Reading*> readings;

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		Sensor(int id, float latitude, float longitude);
		~Sensor();
		/* ACCESSORS -------------------------------------------------------- */
		int getId() const;
		void setId(int id);
		float getLatitude() const;
		void setLatitude(float latitude);
		float getLongitude() const;
		void setLongitude(float longitude);
		ReliabilityFlag getReliabilityFlag() const;
		void setReliabilityFlag(ReliabilityFlag reliabilityFlag);
		Individual* getOwner() const;
		void setOwner(Individual* owner);
		map<Date, Reading*> getReadings() const;
		void addReading(Reading* reading);

};

#endif
