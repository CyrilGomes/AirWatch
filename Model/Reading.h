#ifndef READING_H
#define READING_H

#include <unordered_map>
#include <string>
#include "Measurement.h"
#include "Date.h"
using namespace std;

class Reading {

	private:
		int id;
		Date timeStamp;
		unordered_map<string, Measurement*> measurements;
		static unordered_map<string, int[]> atmoTable;

	public:
		Reading(Date timeStamp);
		~Reading();
		int getId();
		void setId(int id);
		Date getTimeStamp();
		void setTimeStamp(Date timeStamp);
		int getAtmoScore();
		unordered_map<string, Measurement*> getMeasurements();
		void addMeasurement(Measurement* measurement, string type);

};

#endif
