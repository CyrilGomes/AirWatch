#ifndef USERSERVICES_H
#define USERSERVICES_H

#include <string>
#include "../Model/User.h"
using namespace std;

class UserServices {

	private:
		static User* currentUser;

	public:
		/* ACCESSORS */
		static User* getCurrentUser();
		static void setCurrentUser(User* user);
		/* METHODS */
		static void authenticate(string uEmail, string uPassword);
		static void registerCompany(string uEmail, string uPassword);
		static void registerIndividual(string uEmail, string uPassword);

};

#endif
