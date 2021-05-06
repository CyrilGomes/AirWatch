#ifndef USER_H
#define USER_H

#include <string>
#include "UserType.h"
using namespace std;

class User {

	protected:
		unsigned int id;
		string password;
		string mail;
		UserType type;
		static int ID;

	public:
		User();
		User(string mail, string password);
		unsigned int getId();
		void setId(unsigned int id);
		string getPassword();
		void setPassword(string password);
		string getMail();
		void setMail(string mail);
		UserType getType();

};

#endif
