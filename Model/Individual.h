#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <list>
#include "Sensor.h"

using namespace std;

namespace Model {
	class Individual : public Model::User {

	private:
		int score;
		list<Sensor> sensorList;

	public:
		Individual(int id, string password, string mail);

		int getScore();

		void setScore(int score);

		list<Model::Sensor> getSensorList();

		void setSensorList(list<Model::Sensor> sensorList);
	};
}

#endif
