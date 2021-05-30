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
		/* CONSTRUCTOR */
		Measurement(string unitType, string description, float value);
		/* ACCESSORS */
		string getUnitType() const;
		void setUnitType(string unitType);
		string getDescription() const;
		void setDescription(string description);
		float getValue() const;
		void setValue(float value);

};

#endif
