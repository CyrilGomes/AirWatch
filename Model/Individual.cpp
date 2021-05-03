#include "Individual.h"

Individual::Individual(int individualId, string mail, string password) : User(mail, password) {
	this->individualId = individualId;
}

int Individual::getIndividualId() {
	return this->individualId;
}

void Individual::setIndividualId(int individualId) {
	this->individualId = individualId;
}

int Individual::getScore() {
	return this->score;
}

void Individual::setScore(int score) {
	this->score = score;
}

list<Sensor> Individual::getSensorList() {
	return this->sensorList;
}

void Individual::addSensor(Sensor* sensor) {
	// TODO
}
