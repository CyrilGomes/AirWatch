#ifndef COMPANY_H
#define COMPANY_H

#include <list>
#include <string>
#include "User.h"
#include "Cleaner.h"
using namespace std;

class Company : public User {

	private:
		list<Cleaner*> cleanerList;
		static unsigned int maxId;

	public:
		Company(unsigned int id, string mail, string password);
		Company(string mail, string password);
		list<Cleaner*> getCleanerList();
		void addCleaner(Cleaner* cleaner);

};

#endif
