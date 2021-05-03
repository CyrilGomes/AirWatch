#include "Cleaner.h"

Cleaner::Cleaner(int id, float latitude, float longitude) {
	// TODO - implement Cleaner::Cleaner
	throw "Not yet implemented";
}

int Cleaner::getId() {
	return this->id;
}

void Cleaner::setId(int id) {
	this->id = id;
}

float Cleaner::getLatitude() {
	return this->latitude;
}

void Cleaner::setLatitude(float latitude) {
	this->latitude = latitude;
}

float Cleaner::getLongitude() {
	return this->longitude;
}

void Cleaner::setLongitude(float longitude) {
	this->longitude = longitude;
}

Date Cleaner::getStartDate() {
	return this->startDate;
}

void Cleaner::setStartDate(Date startDate) {
	this->startDate = startDate;
}

Date Cleaner::getStopDate() {
	return this->stopDate;
}

void Cleaner::setStopDate(Date stopDate) {
	this->stopDate = stopDate;
}

Company Cleaner::getOwner() {
	return this->owner;
}

void Cleaner::setOwner(Company owner) {
	this->owner = owner;
}
