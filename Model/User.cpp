#include "User.h"

int Model::User::getId() {
	return this->id;
}

void Model::User::setId(int id) {
	this->id = id;
}

string Model::User::getPassword() {
	return this->password;
}

void Model::User::setPassword(string password) {
	this->password = password;
}

string Model::User::getMail() {
	return this->mail;
}

void Model::User::setMail(string mail) {
	this->mail = mail;
}

Model::User::User(int id, string password, string mail) {
	// TODO - implement User::User
	throw "Not yet implemented";
}
