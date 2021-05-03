#include "Measurement.h"

Model::Measurement::Measurement(String unitType, String description, float value) {
	// TODO - implement Measurement::Measurement
	throw "Not yet implemented";
}

String Model::Measurement::getUnitType() {
	return this->unitType;
}

void Model::Measurement::setUnitType(String unitType) {
	this->unitType = unitType;
}

String Model::Measurement::getDescription() {
	return this->description;
}

void Model::Measurement::setDescription(String description) {
	this->description = description;
}

float Model::Measurement::getValue() {
	return this->value;
}

void Model::Measurement::setValue(float value) {
	this->value = value;
}
