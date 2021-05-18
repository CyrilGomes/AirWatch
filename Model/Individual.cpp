#include "Individual.h"
#include "../Database/DBManager.h"

unsigned int Individual::maxId = 0;

Individual::Individual(unsigned int id, string mail, string password) : User(mail, password) {
	this->id = id;
	this->type = UserType::individual;
    this->points = 0;
    this->reliabilityFlag = ReliabilityFlag::reliable;
	maxId = max(maxId, id);
}

Individual::Individual(string mail, string password) : User(mail, password) {
	this->id = ++maxId;
	this->type = UserType::individual;
    this->reliabilityFlag = ReliabilityFlag::reliable;
    this->points = 0;
}

int Individual::getPoints() const {
	return this->points;
}

void Individual::setPoints(int points) {
	this->points = points;
}

void Individual::addPoint() {
    (this->points)++;
	//DBManager::saveLocalData();
}

ReliabilityFlag Individual::getReliabilityFlag() const {
	return this->reliabilityFlag;
}

void Individual::setReliabilityFlag(ReliabilityFlag reliabilityFlag) {
	this->reliabilityFlag = reliabilityFlag;
    for (Sensor* i : sensorList) {
        i->setReliabilityFlag(reliabilityFlag);
    }
	DBManager::saveLocalData();
}

list<Sensor*> Individual::getSensorList() const {
	return this->sensorList;
}

void Individual::addSensor(Sensor* sensor) {
	sensorList.push_back(sensor);
}
