#ifndef USER_H
#define USER_H

using namespace std;

namespace Model {
	class User {

	protected:
		int id;
		string password;
		string mail;

	public:
		int getId();

		void setId(int id);

		string getPassword();

		void setPassword(string password);

		string getMail();

		void setMail(string mail);

		User(int id, string password, string mail);
	};
}

#endif
