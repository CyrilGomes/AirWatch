#ifndef READING_H
#define READING_H

namespace Model {
	class Reading {

	private:
		int id;
		Date timeStamp;
		List measurements;

	public:
		Reading(int id, Date timeStamp);

		int getId();

		void setId(int id);

		Date getTimeStamp();

		void setTimeStamp(Date timeStamp);

		int getAtmoScore();

		List getMeasurements();

		void setMeasurements(List measurements);
	};
}

#endif
