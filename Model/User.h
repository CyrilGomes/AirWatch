#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {

	protected:
		int id;
		string password;
		string mail;
		static int ID;

	public:
		int getId();
		void setId(int id);
		string getPassword();
		void setPassword(string password);
		string getMail();
		void setMail(string mail);
		User(string mail, string password);

};

#endif
