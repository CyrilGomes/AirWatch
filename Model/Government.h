#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include "User.h"
using namespace std;

/* -------------------------------------------------------------------------- */
/* GOVERNMENT (child of User) ----------------------------------------------- */
/* -------------------------------------------------------------------------- */
class Government : public User {

	private:
		static unsigned int maxId;

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		Government(string mail, string password);

};


#endif
