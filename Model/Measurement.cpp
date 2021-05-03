#include "Measurement.h"

Model::Measurement::Measurement(string unitType, string description, float value) {
	// TODO - implement Measurement::Measurement
	throw "Not yet implemented";
}

string Model::Measurement::getUnitType() {
	return this->unitType;
}

void Model::Measurement::setUnitType(string unitType) {
	this->unitType = unitType;
}

string Model::Measurement::getDescription() {
	return this->description;
}

void Model::Measurement::setDescription(string description) {
	this->description = description;
}

float Model::Measurement::getValue() {
	return this->value;
}

void Model::Measurement::setValue(float value) {
	this->value = value;
}
