#include "Reading.h"
#include "../Services/UserServices.h"
#include "User.h"
#include "Individual.h"

/* -------------------------------------------------------------------------- */
/* STATIC TABLE USED TO COMPUTE ATMO SCORES --------------------------------- */
/* -------------------------------------------------------------------------- */
int _atmo_O3   [] = {0, 30, 55, 80, 105, 130, 150, 180, 210, 240};
int _atmo_SO2  [] = {0, 40, 80, 120, 160, 200, 250, 300, 400, 500};
int _atmo_NO2  [] = {0, 30, 55, 85, 110, 135, 165, 200, 275, 400};
int _atmo_PM10 [] = {0, 7, 14, 21, 28, 35, 42, 50, 65, 80};
unordered_map<string, int*> Reading::atmoTable = {
	{"O3",   _atmo_O3},
	{"SO2",  _atmo_SO2},
	{"NO2",  _atmo_NO2},
	{"PM10", _atmo_PM10}
};

/* -------------------------------------------------------------------------- */
/* CONSTRUCTORS & DESTRUCTOR ------------------------------------------------ */
/* -------------------------------------------------------------------------- */
Reading::Reading(Date timeStamp) : timeStamp(timeStamp) 
{
	this->sensor = nullptr;
}
Reading::~Reading() 
{
	for (auto i : measurements) {
		delete i.second;
	}
}

/* -------------------------------------------------------------------------- */
/* ACCESSORS ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
Date Reading::getTimeStamp() const 
{
	return this->timeStamp;
}
void Reading::setTimeStamp(Date timeStamp) 
{
	this->timeStamp = timeStamp;
}
Sensor* Reading::getSensor() const 
{
	return this->sensor;
}
void Reading::setSensor(Sensor* sensor) 
{
	this->sensor = sensor;
}
unordered_map<string, Measurement*> Reading::getMeasurements() const 
{
	return this->measurements;
}
void Reading::addMeasurement(Measurement* measurement, string type) 
{
	measurements[type] = measurement;
}

/* -------------------------------------------------------------------------- */
/* METHOD: atmo() ----------------------------------------------------------- */
/* Calculates the ATMO Index of the reading --------------------------------- */
/* -------------------------------------------------------------------------- */
int Reading::atmo() 
{
	// Give points to owner (unless owner is current user)
	User* currentUser = UserServices::getCurrentUser();
	Individual* owner = sensor->getOwner();
	if (currentUser != nullptr && owner != nullptr && currentUser->getMail() != owner->getMail()) {
		owner->addPoint();
	}
	// Calculate ATMO
	int atmo = 0;
	for (pair<string, Measurement*> i : measurements) {
		int subAtmo = 0;
		for (int k = 0; k < 10; k++) {
			if (Reading::atmoTable[i.first][k] > i.second->getValue()) {
				subAtmo = k - 1;
				break;
			}
		}
		atmo = (subAtmo > atmo) ? subAtmo : atmo;
	}
	return atmo + 1; //ATMO indices start at 1
}
