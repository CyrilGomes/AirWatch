#ifndef CLEANER_H
#define CLEANER_H

class Company;
#include "Date.h"

class Cleaner {

	private:
		int id;
		float latitude;
		float longitude;
		Date startDate;
		Date stopDate;
		Company* owner;

	public:
		Cleaner(int id, float latitude, float longitude, Date startDate, Date stopDate);
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
		Company* getOwner();
		void setOwner(Company* owner);

};

#endif
