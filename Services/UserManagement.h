#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <string>
#include "../Model/User.h"
using namespace std;

class UserManagement {

	private:
		static User currentUser;

	public:
		static User getCurrentUser();
		static void setCurrentUser(User currentUser);
		static User authenticate(string uEmail, string uPassword);
		static bool registerCompany(int companyId);
		static bool registerIndividual(string uEmail, string uPassword);

};

#endif
