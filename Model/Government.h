#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include "User.h"
using namespace std;

class Government : public User {

	private:
		static unsigned int maxId;

	public:
		/* CONSTRUCTOR */
		Government(string mail, string password);

};


#endif
