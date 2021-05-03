#ifndef READING_H
#define READING_H

class Reading {

	private:
		int id;
		Date timeStamp;
		list measurements;

	public:
		Reading(int id, Date timeStamp);

		int getId();

		void setId(int id);

		Date getTimeStamp();

		void setTimeStamp(Date timeStamp);

		int getAtmoScore();

		list getMeasurements();

		void setMeasurements(list measurements);
};

#endif
