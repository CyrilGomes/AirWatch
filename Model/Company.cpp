#include "Company.h"

Company::Company(int id, String password, String mail, int companyId) {
	// TODO - implement Company::Company
	throw "Not yet implemented";
}

int Company::getCompanyId() {
	return this->companyId;
}

void Company::setCompanyId(int companyId) {
	this->companyId = companyId;
}

List Company::getCleanerList() {
	return this->cleanerList;
}

void Company::setCleanerList(List cleanerList) {
	this->cleanerList = cleanerList;
}
