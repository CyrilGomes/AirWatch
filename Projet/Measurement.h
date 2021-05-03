#ifndef MEASUREMENT_H
#define MEASUREMENT_H

namespace Model {
	class Measurement {

	private:
		String unitType;
		String description;
		float value;

	public:
		Measurement(String unitType, String description, float value);

		String getUnitType();

		void setUnitType(String unitType);

		String getDescription();

		void setDescription(String description);

		float getValue();

		void setValue(float value);
	};
}

#endif
