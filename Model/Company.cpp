#include "Company.h"

Company::Company(int id, string password, string mail, int companyId) {
	// TODO - implement Company::Company
	throw "Not yet implemented";
}

int Company::getCompanyId() {
	return this->companyId;
}

void Company::setCompanyId(int companyId) {
	this->companyId = companyId;
}

list<Cleaner> Company::getCleanerList() {
	return this->cleanerList;
}

void Company::setCleanerList(list<Cleaner> cleanerList) {
	this->cleanerList = cleanerList;
}
