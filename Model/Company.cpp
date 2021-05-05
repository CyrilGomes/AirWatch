#include "Company.h"

inline int max(unsigned int x, unsigned int y) {
   return (x > y) ? x : y;
}

unsigned int Company::maxId = 0;

Company::Company(unsigned int id, string mail, string password) : User(mail, password) {
	this->id = id;
	this->type = UserType::company;
	maxId = max(maxId, id);
}

Company::Company(string mail, string password) : User(mail, password) {
	this->id = maxId++;
}

list<Cleaner*> Company::getCleanerList() {
	return this->cleanerList;
}

void Company::addCleaner(Cleaner* cleaner) {
	cleanerList.push_back(cleaner);
}
