#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

class Individual : User {

	private:
		int score;
		list sensorList;

	public:
		Individual(int id, string password, string mail);

		int getScore();

		void setScore(int score);

		list getSensorList();

		void setSensorList(list sensorList);
};

#endif
