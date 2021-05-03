#include "Individual.h"

Model::Individual::Individual(int id, string password, string mail) {
	// TODO - implement Individual::Individual
	throw "Not yet implemented";
}

int Model::Individual::getScore() {
	return this->score;
}

void Model::Individual::setScore(int score) {
	this->score = score;
}

list<Model::Sensor> Model::Individual::getSensorList() {
	return this->sensorList;
}

void Model::Individual::setSensorList(list<Model::Sensor> sensorList) {
	this->sensorList = sensorList;
}
