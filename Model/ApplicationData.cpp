#include "ApplicationData.h"

ApplicationData* ApplicationData::singleton = nullptr;

ApplicationData::ApplicationData() {}

ApplicationData* ApplicationData::getInstance() {
    if (singleton == nullptr) {
        singleton = new ApplicationData();
    }
    return singleton;
}

unordered_map<int, Cleaner*> ApplicationData::getCleanerList() {
	return cleanerList;
}

void ApplicationData::addCleaner(Cleaner* cleaner) {
	cleanerList[cleaner->getId()] = cleaner;
}

unordered_map<int, Sensor*> ApplicationData::getSensorList() {
	return sensorList;
}

void ApplicationData::addSensor(Sensor* sensor) {
	sensorList[sensor->getId()] = sensor;
}

unordered_map<string, User*> ApplicationData::getUserList() {
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
	// TODO - implement ApplicationData::distance
	throw "Not yet implemented";
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
