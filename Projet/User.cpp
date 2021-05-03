#include "User.h"

int Model::User::getId() {
	return this->id;
}

void Model::User::setId(int id) {
	this->id = id;
}

String Model::User::getPassword() {
	return this->password;
}

void Model::User::setPassword(String password) {
	this->password = password;
}

String Model::User::getMail() {
	return this->mail;
}

void Model::User::setMail(String mail) {
	this->mail = mail;
}

Model::User::User(int id, String password, String mail) {
	// TODO - implement User::User
	throw "Not yet implemented";
}
