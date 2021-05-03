#include "UserManagement.h"

Model::User Services::UserManagement::getCurrentUser() {
	return this->currentUser;
}

void Services::UserManagement::setCurrentUser(Model::User currentUser) {
	this->currentUser = currentUser;
}

Model::User Services::UserManagement::authenticate(String uEmail, String uPassword) {
	// TODO - implement UserManagement::authenticate
	throw "Not yet implemented";
}

bool Services::UserManagement::registerCompany(int companyId) {
	// TODO - implement UserManagement::registerCompany
	throw "Not yet implemented";
}

bool Services::UserManagement::registerIndividual(String uEmail, String uPassword) {
	// TODO - implement UserManagement::registerIndividual
	throw "Not yet implemented";
}
