#ifndef CLEANER_H
#define CLEANER_H

#include "Date.h"

namespace Model {
	class Cleaner {

	private:
		int id;
		float latitude;
		float longitude;
		Date startDate;
		Date stopDate;
		Model::Company owner;

	public:
		Cleaner(int id, float latitude, float longitude);

		int getId();

		void setId(int id);

		float getLatitude();

		void setLatitude(float latitude);

		float getLongitude();

		void setLongitude(float longitude);

		Date getStartDate();

		void setStartDate(Date startDate);

		Date getStopDate();

		void setStopDate(Date stopDate);

		Model::Company getOwner();

		void setOwner(Model::Company owner);
	};
}

#endif
