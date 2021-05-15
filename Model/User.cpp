#include "User.h"

User::User(){
}

User::User(string mail, string password) {
	this->mail = mail;
	this->password = password;
}

unsigned int User::getId() const {
	return this->id;
}

void User::setId(unsigned int id) {
	this->id = id;
}

string User::getPassword() const {
	return this->password;
}

void User::setPassword(string password) {
	this->password = password;
}

string User::getMail() const {
	return this->mail;
}

void User::setMail(string mail) {
	this->mail = mail;
}

UserType User::getType() const {
	return this->type;
}
