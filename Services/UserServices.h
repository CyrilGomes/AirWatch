#ifndef USERSERVICES_H
#define USERSERVICES_H

#include <string>
#include "../Model/User.h"
using namespace std;

class UserServices {

	private:
		static User* currentUser;

	public:
		static User* getCurrentUser();
		static void setCurrentUser(User* user);
		static int authenticate(string uEmail, string uPassword);
		static int registerCompany(string uEmail, string uPassword);
		static int registerIndividual(string uEmail, string uPassword);

};

#endif
