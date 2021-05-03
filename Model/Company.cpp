#include "Company.h"

Company::Company(int companyId, string password, string mail) : User(mail, password) {
	this->companyId = companyId;
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

void Company::addCleaner(Cleaner* cleaner) {
	// TODO
}
