#include "Date.h"

int Date::getYear() const
{
	return year;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getMonth() const
{
	return month;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getDay() const
{
	return day;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getHour() const
{
	return hour;
}

void Date::setHour(int hour)
{
	this->hour = hour;
}

string Date::toString() const
{
	string sYear = to_string(year);
	string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
	string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
	string sHour = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
	return sYear + "/" + sMonth + "/" + sDay + " " + sHour + ":00:00";
}

bool Date::operator==(const Date &oDate) const
{
	return (
		getYear() == oDate.getYear() && getMonth() == oDate.getMonth() && getDay() == oDate.getDay() && getHour() == oDate.getHour());
}

bool Date::operator<(const Date &oDate) const
{
	if (getYear() < oDate.getYear())
	{
		return true;
	}
	else if (getYear() == oDate.getYear())
	{
		if (getMonth() < oDate.getMonth())
		{
			return true;
		}
		else if (getMonth() == oDate.getMonth())
		{
			if (getDay() < oDate.getDay())
			{
				return true;
			}
			else if (getDay() == oDate.getDay())
			{
				if (getHour() < oDate.getHour())
				{
					return true;
				}
				else if (getHour() == oDate.getHour())
				{
					return false;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return false;
}

Date &Date::operator=(const Date &oDate)
{
	year = oDate.getYear();
	month = oDate.getMonth();
	day = oDate.getDay();
	hour = oDate.getHour();
	return *this;
}

ostream &operator<<(ostream &output, const Date &d)
{
	output << d.toString();
	return output;
}
istream &operator>>(istream &input, Date &d)
{
	//TODO: Verifier si ca ne viol pas les couches
	tm t = {};

	input >> std::get_time(&t, "%d/%m/%Y");
	if (input.fail())
	{
		cout << "Parse failed\n";
	}
	else
	{
		d.setYear(1900+t.tm_year); //tm_year correspond au nombre d'années depuis 1900
		d.setMonth(1+t.tm_mon); //tm_mon commence à 0 et pas 1
		d.setDay(t.tm_mday);
		d.setHour(0);
	}

	return input;
}