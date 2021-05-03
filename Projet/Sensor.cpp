#include "Sensor.h"

Model::Sensor::Sensor(int id, float latitude, float longitude) {
	// TODO - implement Sensor::Sensor
	throw "Not yet implemented";
}

int Model::Sensor::getId() {
	return this->id;
}

void Model::Sensor::setId(int id) {
	this->id = id;
}

float Model::Sensor::getLatitude() {
	return this->latitude;
}

void Model::Sensor::setLatitude(float latitude) {
	this->latitude = latitude;
}

float Model::Sensor::getLongitude() {
	return this->longitude;
}

void Model::Sensor::setLongitude(float longitude) {
	this->longitude = longitude;
}

Model::User Model::Sensor::getOwner() {
	return this->owner;
}

void Model::Sensor::setOwner(Model::User owner) {
	this->owner = owner;
}

List Model::Sensor::getReadings() {
	return this->readings;
}

void Model::Sensor::setReadings(List readings) {
	this->readings = readings;
}
