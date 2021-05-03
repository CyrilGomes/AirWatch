#include "Individual.h"

Model::Individual::Individual(int id, String password, String mail) {
	// TODO - implement Individual::Individual
	throw "Not yet implemented";
}

int Individual::getScore() {
	return this->score;
}

void Individual::setScore(int score) {
	this->score = score;
}

List Individual::getSensorList() {
	return this->sensorList;
}

void Individual::setSensorList(List sensorList) {
	this->sensorList = sensorList;
}
