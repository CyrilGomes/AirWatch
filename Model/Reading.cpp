#include "Reading.h"

unordered_map<string, int[]> atmoTable = {
	make_pair("O3", {0, 30, 55, 80, 105, 130, 150, 180, 210, 240}),
	make_pair("SO2", {0, 40, 80, 120, 160, 200, 250, 300, 400, 500}),
	make_pair("NO2", {0, 30, 55, 85, 110, 135, 165, 200, 275, 400}),
	make_pair("PM10", {0, 7, 14, 21, 28, 35, 42, 50, 65, 80})
};

Reading::Reading(Date timeStamp) : timeStamp(timeStamp) {
}

Reading::~Reading() {
	for (auto i : measurements) {
		delete i.second;
	}
}

int Reading::getId() {
	return this->id;
}

void Reading::setId(int id) {
	this->id = id;
}

Date Reading::getTimeStamp() {
	return this->timeStamp;
}

void Reading::setTimeStamp(Date timeStamp) {
	this->timeStamp = timeStamp;
}

int Reading::getAtmoScore() {
	int atmo = 0;
	for (pair<string, Measurement*> i : measurements) {
		int subAtmo = 0;
		for (int j = 1; j < 10; j++) {
			if (Reading::atmoTable[i.first][j] > i.second->getValue()) {
				subAtmo = j - 1;
				break;
			}
		}
		atmo = (subAtmo > atmo) ? subAtmo : atmo;
	}
	return atmo;
}

unordered_map<string, Measurement*> Reading::getMeasurements() {
	return this->measurements;
}

void Reading::addMeasurement(Measurement* measurement, string type) {
	measurements[type] = measurement;
}
