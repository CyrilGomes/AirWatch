#include "Sensor.h"

Sensor::Sensor(int id, float latitude, float longitude) {
	// TODO - implement Sensor::Sensor
	throw "Not yet implemented";
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

User Sensor::getOwner() {
	return this->owner;
}

void Sensor::setOwner(User owner) {
	this->owner = owner;
}

list<Reading> Sensor::getReadings() {
	return this->readings;
}

void Sensor::setReadings(list<Reading> readings) {
	this->readings = readings;
}
