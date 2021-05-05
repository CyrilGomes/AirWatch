#include "Sensor.h"

Sensor::Sensor(int id, float latitude, float longitude) {
	this->id = id;
	this->latitude = latitude;
	this->longitude = longitude;
}

Sensor::~Sensor() {
	for (auto i : readings) {
		delete i.second;
	}
}

int Sensor::getId() {
	return this->id;
}

void Sensor::setId(int id) {
	this->id = id;
}

float Sensor::getLatitude() {
	return this->latitude;
}

void Sensor::setLatitude(float latitude) {
	this->latitude = latitude;
}

float Sensor::getLongitude() {
	return this->longitude;
}

void Sensor::setLongitude(float longitude) {
	this->longitude = longitude;
}

ReliabilityFlag Sensor::getReliabilityFlag() {
	return this->reliabilityFlag;
}

void Sensor::setReliabilityFlag(ReliabilityFlag reliabilityFlag) {
	this->reliabilityFlag = reliabilityFlag;
}

Individual* Sensor::getOwner() {
	return this->owner;
}

void Sensor::setOwner(Individual* owner) {
	this->owner = owner;
}

map<Date, Reading*> Sensor::getReadings() {
	return this->readings;
}

void Sensor::addReading(Reading* reading) {
	readings[reading->getTimeStamp()] = reading;
}
