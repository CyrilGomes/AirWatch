#include "ApplicationData.h"
#include <cmath>
#include <math.h>

ApplicationData* ApplicationData::singleton = nullptr;

ApplicationData::ApplicationData() {}

ApplicationData* ApplicationData::getInstance() {
    if (singleton == nullptr) {
        singleton = new ApplicationData();
    }
    return singleton;
}

unordered_map<int, Cleaner*> ApplicationData::getCleanerList() const {
	return cleanerList;
}

void ApplicationData::addCleaner(Cleaner* cleaner) {
	cleanerList[cleaner->getId()] = cleaner;
}

unordered_map<int, Sensor*> ApplicationData::getSensorList() const {
	return sensorList;
}

void ApplicationData::addSensor(Sensor* sensor) {
	sensorList[sensor->getId()] = sensor;
}

unordered_map<string, User*> ApplicationData::getUserList() const {
	return userList;
}

void ApplicationData::addUser(User* user) {
	userList[user->getMail()] = user;
}

void ApplicationData::updateUserList(string oldKey) {
    User* user = userList[oldKey];
    userList.erase(oldKey);
    userList[user->getMail()] = user;
}


float ApplicationData::distance(float lat1, float lon1, float lat2, float lon2) {
    float earthRadius = 6378137.0;
    float lat1_rad = lat1 * M_PI/180.0; float lon1_rad = lon1 * M_PI/180.0;
    float lat2_rad = lat2 * M_PI/180.0; float lon2_rad = lon2 * M_PI/180.0;
    return acos(sin(lat1_rad)*sin(lat2_rad)+cos(lat1_rad)*cos(lat2_rad)*cos(lon2_rad-lon1_rad))*earthRadius;
}

ApplicationData::~ApplicationData() {
	for (auto i : userList) {
		delete i.second;
	}
	for (auto i : cleanerList) {
		delete i.second;
	}
	for (auto i : sensorList) {
		delete i.second;
	}
}
