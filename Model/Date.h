#ifndef DATE_H
#define DATE_H


	class Date {

	private:
		int Year;
		int Month;
		int Day;
		int Hour;

	public:
		int getYear();

		void setYear(int Year);

		int getMonth();

		void setMonth(int Month);

		int getDay();

		void setDay(int Day);

		int getHour();

		void setHour(int Hour);
	};


#endif