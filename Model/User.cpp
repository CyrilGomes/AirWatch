#include "User.h"

int User::getId() {
	return this->id;
}

void User::setId(int id) {
	this->id = id;
}

string User::getPassword() {
	return this->password;
}

void User::setPassword(string password) {
	this->password = password;
}

string User::getMail() {
	return this->mail;
}

void User::setMail(string mail) {
	this->mail = mail;
}

User::User(int id, string password, string mail) {
	this->mail = mail;
	this->id = id;
	this->password = password;
	throw "Not yet implemented";
}
