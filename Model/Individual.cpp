#include "Individual.h"

inline int max(unsigned int x, unsigned int y) {
   return (x > y) ? x : y;
}

unsigned int Individual::maxId = 0;

Individual::Individual(unsigned int id, string mail, string password) : User(mail, password) {
	this->id = id;
	this->type = UserType::individual;
	maxId = max(maxId, id);
}

Individual::Individual(string mail, string password) : User(mail, password) {
	this->id = maxId++;
}

int Individual::getPoints() {
	return this->points;
}

void Individual::setPoints(int points) {
	this->points = points;
}

ReliabilityFlag Individual::getReliabilityFlag() {
	return this->reliabilityFlag;
}

void Individual::setReliabilityFlag(ReliabilityFlag reliabilityFlag) {
	this->reliabilityFlag = reliabilityFlag;
}

list<Sensor*> Individual::getSensorList() {
	return this->sensorList;
}

void Individual::addSensor(Sensor* sensor) {
	sensorList.push_back(sensor);
}
