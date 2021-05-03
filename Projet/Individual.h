#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

namespace Model {
	class Individual : Model::User {

	private:
		int score;
		List sensorList;

	public:
		Individual(int id, String password, String mail);

		int getScore();

		void setScore(int score);

		List getSensorList();

		void setSensorList(List sensorList);
	};
}

#endif
