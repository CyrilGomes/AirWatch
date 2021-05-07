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
		int id;
		Date timeStamp;
		Sensor* sensor;
		unordered_map<string, Measurement*> measurements;
		static unordered_map<string, int*> atmoTable;

	public:
		Reading(Date timeStamp);
		~Reading();
		int getId() const;
		void setId(int id);
		Date getTimeStamp() const;
		void setTimeStamp(Date timeStamp);
		Sensor* getSensor() const;
		void setSensor(Sensor* sensor);
		unordered_map<string, Measurement*> getMeasurements() const;
		void addMeasurement(Measurement* measurement, string type);
		int atmo();

};

#endif
