#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

namespace Services {
	class UserManagement {

	private:
		Model::User currentUser;

	public:
		Model::User getCurrentUser();

		void setCurrentUser(Model::User currentUser);

		Model::User authenticate(String uEmail, String uPassword);

		bool registerCompany(int companyId);

		bool registerIndividual(String uEmail, String uPassword);
	};
}

#endif
