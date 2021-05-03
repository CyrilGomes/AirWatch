#ifndef READING_H
#define READING_H

#include <list>
#include "Measurement.h"

using namespace std;

namespace Model {
	class Reading {

	private:
		int id;
		Date timeStamp;
		list<Model::Measurement> measurements;

	public:
		Reading(int id, Date timeStamp);

		int getId();

		void setId(int id);

		Date getTimeStamp();

		void setTimeStamp(Date timeStamp);

		int getAtmoScore();

		list<Model::Measurement> getMeasurements();

		void setMeasurements(list<Model::Measurement> measurements);
	};
}

#endif
