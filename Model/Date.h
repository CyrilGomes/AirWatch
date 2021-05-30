#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

/* -------------------------------------------------------------------------- */
/* DATE --------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
class Date {

	private:
		int hour;
		int day;
		int month;
		int year;

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		Date();
		Date(int hour, int day, int month, int year);
		/* ACCESSORS -------------------------------------------------------- */
		int getYear() const;
		void setYear(int year);
		int getMonth() const;
		void setMonth(int month);
		int getDay() const;
		void setDay(int day);
		int getHour() const;
		void setHour(int hour);
		string toString() const;
		/* OPERATOR OVERLOADS ----------------------------------------------- */
		bool operator==(const Date& oDate) const;
		bool operator<(const Date& oDate) const;
		Date& operator=(const Date& oDate);
		friend ostream& operator<<(ostream& output, const Date& date);
		friend istream& operator>>(istream& input, Date& date);

};

#endif
