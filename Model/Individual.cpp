#include "Individual.h"

Individual::Individual(int id, string password, string mail) : User(id,password,mail) {
	// TODO - implement Individual::Individual
	
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

void Individual::setSensorList(list<Sensor> sensorList) {
	this->sensorList = sensorList;
}
