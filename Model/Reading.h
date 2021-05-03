#ifndef READING_H
#define READING_H

#include <ctime>
#include <list>
using namespace std;

#include "Measurement.h"

	class Reading {

	private:
		int id;
		tm timeStamp;
		list<Measurement> measurements;

	public:
		Reading(int id, tm timeStamp);

		int getId();

		void setId(int id);

		tm getTimeStamp();

		void setTimeStamp(tm timeStamp);

		int getAtmoScore();

		list<Measurement> getMeasurements();

		void setMeasurements(list<Measurement> measurements);
	};


#endif
