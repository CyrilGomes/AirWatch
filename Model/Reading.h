#ifndef READING_H
#define READING_H

class Sensor;
#include <unordered_map>
#include <string>
#include "Measurement.h"
#include "Date.h"
using namespace std;

class Reading {

	private:
		Date timeStamp;
		Sensor* sensor;
		unordered_map<string, Measurement*> measurements;
		static unordered_map<string, int*> atmoTable;

	public:
		/* CONSTRUCTOR & DESTRUCTOR */
		Reading(Date timeStamp);
		~Reading();
		/* ACCESSORS */
		Date getTimeStamp() const;
		void setTimeStamp(Date timeStamp);
		Sensor* getSensor() const;
		void setSensor(Sensor* sensor);
		unordered_map<string, Measurement*> getMeasurements() const;
		void addMeasurement(Measurement* measurement, string type);
		/* METHODS */
		int atmo();

};

#endif
