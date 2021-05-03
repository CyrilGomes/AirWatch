#include "Company.h"

Model::Company::Company(int id, String password, String mail, int companyId) {
	// TODO - implement Company::Company
	throw "Not yet implemented";
}

int Model::Company::getCompanyId() {
	return this->companyId;
}

void Model::Company::setCompanyId(int companyId) {
	this->companyId = companyId;
}

List Model::Company::getCleanerList() {
	return this->cleanerList;
}

void Model::Company::setCleanerList(List cleanerList) {
	this->cleanerList = cleanerList;
}
