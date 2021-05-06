#include "UserManagement.h"

User UserManagement::getCurrentUser() {
	return currentUser;
}

void UserManagement::setCurrentUser(User currentUser) {
	currentUser = currentUser;
}

User UserManagement::authenticate(string uEmail, string uPassword) {
	// TODO - implement UserManagement::authenticate
	throw "Not yet implemented";
}

bool UserManagement::registerCompany(int companyId) {
	// TODO - implement UserManagement::registerCompany
	throw "Not yet implemented";
}

bool UserManagement::registerIndividual(string uEmail, string uPassword) {
	// TODO - implement UserManagement::registerIndividual
	throw "Not yet implemented";
}
