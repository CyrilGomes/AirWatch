#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <list>
#include <string>
#include "Sensor.h"
#include "User.h"
using namespace std;

class Individual : public User {

	private:
		int individualId;
		int score;
		list<Sensor> sensorList;

	public:
		Individual(int individualId, string mail, string password);
		Individual();
		int getIndividualId();
		void setIndividualId(int individualId);
		int getScore();
		void setScore(int score);
		list<Sensor> getSensorList();
		void addSensor(Sensor* sensor);

};

#endif
