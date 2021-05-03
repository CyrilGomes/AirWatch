#include "Measurement.h"

Measurement::Measurement(string unitType, string description, float value) {
	// TODO - implement Measurement::Measurement
	throw "Not yet implemented";
}

string Measurement::getUnitType() {
	return this->unitType;
}

void Measurement::setUnitType(string unitType) {
	this->unitType = unitType;
}

string Measurement::getDescription() {
	return this->description;
}

void Measurement::setDescription(string description) {
	this->description = description;
}

float Measurement::getValue() {
	return this->value;
}

void Measurement::setValue(float value) {
	this->value = value;
}
