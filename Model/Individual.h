#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include <string>
#include "Sensor.h"
#include "User.h"
using namespace std;

/* -------------------------------------------------------------------------- */
/* INDIVIDUAL (child of User) ----------------------------------------------- */
/* -------------------------------------------------------------------------- */
class Individual : public User {

	private:
		int points;
		ReliabilityFlag reliabilityFlag;
		vector<Sensor*> sensorList;
		static unsigned int maxId;

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		Individual(unsigned int id, string mail, string password);
		Individual(string mail, string password);
		~Individual();
		/* ACCESSORS -------------------------------------------------------- */
		int getPoints() const;
		void setPoints(int points);
		void addPoint();
		ReliabilityFlag getReliabilityFlag() const;
		void setReliabilityFlag(ReliabilityFlag reliabilityFlag);
		vector<Sensor*> getSensorList() const;
		void addSensor(Sensor* sensor);

};

#endif
