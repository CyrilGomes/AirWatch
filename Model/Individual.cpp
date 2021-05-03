#include "Individual.h"

Individual::Individual(int id, string password, String mail) {
	// TODO - implement Individual::Individual
	throw "Not yet implemented";
}

int Individual::getScore() {
	return this->score;
}

void Individual::setScore(int score) {
	this->score = score;
}

list Individual::getSensorList() {
	return this->sensorList;
}

void Individual::setSensorList(List sensorList) {
	this->sensorList = sensorList;
}
