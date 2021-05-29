#include "Company.h"

unsigned int Company::maxId = 0;

Company::Company(unsigned int id, string mail, string password) : User(mail, password) {
	this->id = id;
	this->type = UserType::company;
	maxId = max(maxId, id);
}

Company::Company(string mail, string password) : User(mail, password) {
	this->id = ++maxId;
	this->type = UserType::company;
}

vector<Cleaner*> Company::getCleanerList() const {
	return this->cleanerList;
}

void Company::addCleaner(Cleaner* cleaner) {
	cleanerList.push_back(cleaner);
}

Company::~Company() {
	vector<Cleaner*>().swap(cleanerList);
}