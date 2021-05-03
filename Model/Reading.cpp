#include "Reading.h"

Model::Reading::Reading(int id, Date timeStamp) {
	// TODO - implement Reading::Reading
	throw "Not yet implemented";
}

int Model::Reading::getId() {
	return this->id;
}

void Model::Reading::setId(int id) {
	this->id = id;
}

Date Model::Reading::getTimeStamp() {
	return this->timeStamp;
}

void Model::Reading::setTimeStamp(Date timeStamp) {
	this->timeStamp = timeStamp;
}

int Model::Reading::getAtmoScore() {
	// TODO - implement Reading::getAtmoScore
	throw "Not yet implemented";
}

list<Model::Measurement> Model::Reading::getMeasurements() {
	return this->measurements;
}

void Model::Reading::setMeasurements(list<Model::Measurement> measurements) {
	this->measurements = measurements;
}
