#ifndef READING_H
#define READING_H

#include <list>
#include "Measurement.h"
#include "Date.h"

using namespace std;

class Reading
{

private:
	int id;
	Date timeStamp;
	list<Measurement> measurements;

public:
	Reading(int id, Date timeStamp);

	int getId();

	void setId(int id);

	Date getTimeStamp();

	void setTimeStamp(Date timeStamp);

	int getAtmoScore();

	list<Measurement> getMeasurements();

	void setMeasurements(list<Measurement> measurements);
};

#endif
