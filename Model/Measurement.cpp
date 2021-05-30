#include "Measurement.h"

/* -------------------------------------------------------------------------- */
/* CONSTRUCTORS & DESTRUCTOR ------------------------------------------------ */
/* -------------------------------------------------------------------------- */
Measurement::Measurement(string unitType, string description, float value) : unitType(unitType), description(description), value(value)  
{
}

/* -------------------------------------------------------------------------- */
/* ACCESSORS ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
string Measurement::getUnitType() const 
{
	return this->unitType;
}
void Measurement::setUnitType(string unitType) 
{
	this->unitType = unitType;
}
string Measurement::getDescription() const 
{
	return this->description;
}
void Measurement::setDescription(string description) 
{
	this->description = description;
}
float Measurement::getValue() const 
{
	return this->value;
}
void Measurement::setValue(float value) 
{
	this->value = value;
}
