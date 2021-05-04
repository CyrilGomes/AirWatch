#include "Reading.h"

Reading::Reading(Date timeStamp) : timeStamp(timeStamp) {
}

Reading::~Reading() {
	for (auto i : measurements) {
		delete i.second;
	}
}

int Reading::getId() {
	return this->id;
}

void Reading::setId(int id) {
	this->id = id;
}

Date Reading::getTimeStamp() {
	return this->timeStamp;
}

void Reading::setTimeStamp(Date timeStamp) {
	this->timeStamp = timeStamp;
}

int Reading::getAtmoScore() {
	// TODO - implement Reading::getAtmoScore
	throw "Not yet implemented";
}

unordered_map<string, Measurement*> Reading::getMeasurements() {
	return this->measurements;
}

void Reading::addMeasurement(Measurement* measurement, string type) {
	measurements[type] = measurement;
}
