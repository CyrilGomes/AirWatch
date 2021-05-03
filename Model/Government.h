#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
using namespace std;

#include "User.h"


	class Government : User {


	public:
		Government(int id, string password, string mail);
	};


#endif
