#include "Government.h"

unsigned int Government::maxId = 0;

Government::Government(string mail, string password) : User(mail, password) {
	this->id = maxId++;
	this->type = UserType::government;
}
