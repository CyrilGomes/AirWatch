#ifndef MEASUREMENT_H
#define MEASUREMENT_H

using namespace std;

namespace Model {
	class Measurement {

	private:
		string unitType;
		string description;
		float value;

	public:
		Measurement(string unitType, string description, float value);

		string getUnitType();

		void setUnitType(string unitType);

		string getDescription();

		void setDescription(string description);

		float getValue();

		void setValue(float value);
	};
}

#endif
