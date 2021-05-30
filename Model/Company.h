#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include "User.h"
#include "Cleaner.h"
using namespace std;

class Company : public User {

	private:
		vector<Cleaner*> cleanerList;
		static unsigned int maxId;

	public:
		/* CONSTRUCTORS & DESTRUCTOR */
		Company(unsigned int id, string mail, string password);
		Company(string mail, string password);
		~Company();
		/* ACCESSORS */
		vector<Cleaner*> getCleanerList() const;
		void addCleaner(Cleaner* cleaner);

};

#endif
