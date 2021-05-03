#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <list>
#include "Sensor.h"
#include <string>
using namespace std;

class Individual : public User
{

private:
	int score;
	list<Sensor> sensorList;

public:
	Individual(int id, string password, string mail);
	Individual();
	int getScore();

	void setScore(int score);

	list<Sensor> getSensorList();

	void setSensorList(list<Sensor> sensorList);
};

#endif
