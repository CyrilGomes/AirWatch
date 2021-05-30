#ifndef CLEANER_H
#define CLEANER_H

class Company;
#include "Date.h"

/* -------------------------------------------------------------------------- */
/* CLEANER ------------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */
class Cleaner {

	private:
		int id;
		float latitude;
		float longitude;
		Date startDate;
		Date stopDate;
		Company* owner;

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		Cleaner(int id, float latitude, float longitude, Date startDate, Date stopDate);
		/* ACCESSORS -------------------------------------------------------- */
		int getId() const;
		void setId(int id);
		float getLatitude() const;
		void setLatitude(float latitude);
		float getLongitude() const;
		void setLongitude(float longitude);
		Date getStartDate() const;
		void setStartDate(Date startDate);
		Date getStopDate() const;
		void setStopDate(Date stopDate);
		Company* getOwner() const;
		void setOwner(Company* owner);

};

#endif
