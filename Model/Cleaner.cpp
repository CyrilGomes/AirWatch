#include "Cleaner.h"

Model::Cleaner::Cleaner(int id, float latitude, float longitude) {
	// TODO - implement Cleaner::Cleaner
	throw "Not yet implemented";
}

int Model::Cleaner::getId() {
	return this->id;
}

void Model::Cleaner::setId(int id) {
	this->id = id;
}

float Model::Cleaner::getLatitude() {
	return this->latitude;
}

void Model::Cleaner::setLatitude(float latitude) {
	this->latitude = latitude;
}

float Model::Cleaner::getLongitude() {
	return this->longitude;
}

void Model::Cleaner::setLongitude(float longitude) {
	this->longitude = longitude;
}

Date Model::Cleaner::getStartDate() {
	return this->startDate;
}

void Model::Cleaner::setStartDate(Date startDate) {
	this->startDate = startDate;
}

Date Model::Cleaner::getStopDate() {
	return this->stopDate;
}

void Model::Cleaner::setStopDate(Date stopDate) {
	this->stopDate = stopDate;
}

Model::Company Model::Cleaner::getOwner() {
	return this->owner;
}

void Model::Cleaner::setOwner(Model::Company owner) {
	this->owner = owner;
}
