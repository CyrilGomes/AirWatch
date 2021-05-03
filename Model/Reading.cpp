#include "Reading.h"

Reading::Reading(int id, tm timeStamp) {
	// TODO - implement Reading::Reading
	throw "Not yet implemented";
}

int Reading::getId() {
	return this->id;
}

void Reading::setId(int id) {
	this->id = id;
}

tm Reading::getTimeStamp() {
	return this->timeStamp;
}

void Reading::setTimeStamp(tm timeStamp) {
	this->timeStamp = timeStamp;
}

int Reading::getAtmoScore() {
	// TODO - implement Reading::getAtmoScore
	throw "Not yet implemented";
}

list<Measurement> Reading::getMeasurements() {
	return this->measurements;
}

void Reading::setMeasurements(list<Measurement> measurements) {
	this->measurements = measurements;
}
