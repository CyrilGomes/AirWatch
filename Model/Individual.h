#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <list>
#include <string>
#include "Sensor.h"
#include "User.h"
using namespace std;

class Individual : public User {

	private:
		int points;
		ReliabilityFlag reliabilityFlag;
		list<Sensor*> sensorList;
		static unsigned int maxId;

	public:
		Individual(unsigned int id, string mail, string password);
		Individual(string mail, string password);
		int getPoints() const;
		void setPoints(int points);
		void addPoint();
		ReliabilityFlag getReliabilityFlag() const;
		void setReliabilityFlag(ReliabilityFlag reliabilityFlag);
		list<Sensor*> getSensorList() const;
		void addSensor(Sensor* sensor);

};

#endif
