#include "Sensor.h"

/* -------------------------------------------------------------------------- */
/* CONSTRUCTORS & DESTRUCTOR ------------------------------------------------ */
/* -------------------------------------------------------------------------- */
Sensor::Sensor(int id, float latitude, float longitude) : id(id), latitude(latitude), longitude(longitude) 
{
	this->reliabilityFlag = ReliabilityFlag::reliable;
	this->owner = nullptr;
}
Sensor::~Sensor() 
{
	for (auto i : readings) {
		delete i.second;
	}
}

/* -------------------------------------------------------------------------- */
/* ACCESSORS ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
int Sensor::getId() const
{
	return this->id;
}
void Sensor::setId(int id) 
{
	this->id = id;
}
float Sensor::getLatitude() const 
{
	return this->latitude;
}
void Sensor::setLatitude(float latitude) 
{
	this->latitude = latitude;
}
float Sensor::getLongitude() const 
{
	return this->longitude;
}
void Sensor::setLongitude(float longitude) 
{
	this->longitude = longitude;
}
ReliabilityFlag Sensor::getReliabilityFlag() const 
{
	return this->reliabilityFlag;
}
void Sensor::setReliabilityFlag(ReliabilityFlag reliabilityFlag) 
{
	this->reliabilityFlag = reliabilityFlag;
}
Individual* Sensor::getOwner() const 
{
	return this->owner;
}
void Sensor::setOwner(Individual* owner) 
{
	this->owner = owner;
}
map<Date, Reading*> Sensor::getReadings() const 
{
	return this->readings;
}
void Sensor::addReading(Reading* reading) 
{
	readings[reading->getTimeStamp()] = reading;
}
