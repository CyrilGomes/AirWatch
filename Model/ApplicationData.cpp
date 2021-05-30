#include "ApplicationData.h"
#include <cmath>
#include <math.h>

/* -------------------------------------------------------------------------- */
/* CONSTRUCTORS & DESTRUCTOR ------------------------------------------------ */
/* -------------------------------------------------------------------------- */
ApplicationData::ApplicationData() {}
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

/* -------------------------------------------------------------------------- */
/* SINGLETON ACCESSOR ------------------------------------------------------- */
/* Only one instance of this class is allowed at one time. This ensures data  */
/* integrity (everything is stored here) ------------------------------------ */
/* -------------------------------------------------------------------------- */
ApplicationData* ApplicationData::singleton = nullptr;
ApplicationData* ApplicationData::getInstance() 
{
    if (singleton == nullptr) {
        singleton = new ApplicationData();
    }
    return singleton;
}

/* -------------------------------------------------------------------------- */
/* ACCESSORS ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
unordered_map<int, Cleaner*> ApplicationData::getCleanerList() const 
{
	return cleanerList;
}
void ApplicationData::addCleaner(Cleaner* cleaner) 
{
	cleanerList[cleaner->getId()] = cleaner;
}
unordered_map<int, Sensor*> ApplicationData::getSensorList() const 
{
	return sensorList;
}
void ApplicationData::addSensor(Sensor* sensor) 
{
	sensorList[sensor->getId()] = sensor;
}
unordered_map<string, User*> ApplicationData::getUserList() const 
{
	return userList;
}
void ApplicationData::addUser(User* user) 
{
	userList[user->getMail()] = user;
}

/* -------------------------------------------------------------------------- */
/* METHOD: updateUserList() ------------------------------------------------- */
/* Updates the user list again (in case the user's email changes on load, key */
/* must be updated here as well) -------------------------------------------- */
/* -------------------------------------------------------------------------- */
void ApplicationData::updateUserList(string oldKey) {
    User* user = userList[oldKey];
    userList.erase(oldKey);
    userList[user->getMail()] = user;
}
