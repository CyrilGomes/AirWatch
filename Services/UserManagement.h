#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <string>
#include "../Model/User.h"
using namespace std;

class UserManagement {

	private:
		User currentUser;

	public:
		User getCurrentUser();
		void setCurrentUser(User currentUser);
		User authenticate(string uEmail, string uPassword);
		bool registerCompany(int companyId);
		bool registerIndividual(string uEmail, string uPassword);

};

#endif
