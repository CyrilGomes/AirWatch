#include "Individual.h"

Model::Individual::Individual(int id, String password, String mail) {
	// TODO - implement Individual::Individual
	throw "Not yet implemented";
}

int Model::Individual::getScore() {
	return this->score;
}

void Model::Individual::setScore(int score) {
	this->score = score;
}

List Model::Individual::getSensorList() {
	return this->sensorList;
}

void Model::Individual::setSensorList(List sensorList) {
	this->sensorList = sensorList;
}
