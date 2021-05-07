#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>
using namespace std;

class Measurement {

	private:
		string unitType;
		string description;
		float value;

	public:
		Measurement(string unitType, string description, float value);
		string getUnitType() const;
		void setUnitType(string unitType);
		string getDescription() const;
		void setDescription(string description);
		float getValue() const;
		void setValue(float value);

};

#endif
