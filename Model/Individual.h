#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <list>
using namespace std;

#include "User.h"
#include "Sensor.h"
#include "ReliabilityFlag.h"


	class Individual : User {

	private:
		int score;
		list<Sensor> sensorList;

	public:
		Individual(int id, string password, string mail);

		int getScore();

		void setScore(int score);

		list<Sensor> getSensorList();

		void setSensorList(list<Sensor> sensorList);
	};


#endif
