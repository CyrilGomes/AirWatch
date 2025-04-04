#ifndef USER_H
#define USER_H

#include <string>
#include "UserType.h"
using namespace std;

/* -------------------------------------------------------------------------- */
/* USER --------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
class User {

	protected:
		unsigned int id;
		string password;
		string mail;
		UserType type;

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		User();
		User(string mail, string password);
		virtual ~User() {};
		/* ACCESSORS -------------------------------------------------------- */
		unsigned int getId() const;
		void setId(unsigned int id);
		string getPassword() const;
		void setPassword(string password);
		string getMail() const;
		void setMail(string mail);
		UserType getType() const;

};

#endif
