#include "Sensor.h"

Sensor::Sensor(int id, float latitude, float longitude) {
	this->id = id;
	this->latitude = latitude;
	this->longitude = longitude;
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

Individual* Sensor::getOwner() {
	return this->owner;
}

void Sensor::setOwner(Individual* owner) {
	this->owner = owner;
}

list<Reading> Sensor::getReadings() {
	return this->readings;
}

void Sensor::setReadings(list<Reading> readings) {
	this->readings = readings;
}
