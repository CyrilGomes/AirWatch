#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

class Date {

	private:
		int year;
		int month;
		int day;
		int hour;

	public:
		int getYear() const;
		void setYear(int year);
		int getMonth() const;
		void setMonth(int month);
		int getDay() const;
		void setDay(int day);
		int getHour() const;
		void setHour(int hour);
		string toString() const;
		bool operator==(const Date& oDate) const;
		bool operator<(const Date& oDate) const;
		Date& operator=(const Date& oDate);
		friend ostream& operator<<(ostream& output, const Date& date);
		friend istream& operator>>(istream& input, Date& date);

};

#endif
