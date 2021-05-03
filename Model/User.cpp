#include "User.h"

int User::ID = 0;

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

User::User(string mail, string password) {
	this->mail = mail;
	this->password = password;
	this->id = ID++;
}
