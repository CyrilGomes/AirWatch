#include "Date.h"

int Model::Date::getYear() {
	return Year;
}

void Model::Date::setYear(int Year) {
	this->Year = Year;
}

int Model::Date::getMonth() {
	return Month;
}

void Model::Date::setMonth(int Month) {
	this->Month = Month;
}

int Model::Date::getDay() {
	return Day;
}

void Model::Date::setDay(int Day) {
	this->Day = Day;
}

int Model::Date::getHour() {
	return Hour;
}

void Model::Date::setHour(int Hour) {
	this->Hour = Hour;
}
