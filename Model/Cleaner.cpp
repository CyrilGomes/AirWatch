#include "Cleaner.h"

/* -------------------------------------------------------------------------- */
/* CONSTRUCTORS & DESTRUCTOR ------------------------------------------------ */
/* -------------------------------------------------------------------------- */
Cleaner::Cleaner(int id, float latitude, float longitude, Date startDate, Date stopDate) : id(id), latitude(latitude), longitude(longitude), startDate(startDate), stopDate(stopDate) 
{
	this->owner = nullptr;
}

/* -------------------------------------------------------------------------- */
/* ACCESSORS ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
int Cleaner::getId() const 
{
	return this->id;
}
void Cleaner::setId(int id) 
{
	this->id = id;
}
float Cleaner::getLatitude() const 
{
	return this->latitude;
}
void Cleaner::setLatitude(float latitude) 
{
	this->latitude = latitude;
}
float Cleaner::getLongitude() const 
{
	return this->longitude;
}
void Cleaner::setLongitude(float longitude) 
{
	this->longitude = longitude;
}
Date Cleaner::getStartDate() const 
{
	return this->startDate;
}
void Cleaner::setStartDate(Date startDate) 
{
	this->startDate = startDate;
}
Date Cleaner::getStopDate() const 
{
	return this->stopDate;
}
void Cleaner::setStopDate(Date stopDate) 
{
	this->stopDate = stopDate;
}
Company* Cleaner::getOwner() const 
{
	return this->owner;
}
void Cleaner::setOwner(Company* owner) 
{
	this->owner = owner;
}
