#ifndef COMPANY_H
#define COMPANY_H

#include <list>
#include <string>
#include "User.h"
#include "Cleaner.h"
using namespace std;

class Company : public User {

	private:
		int companyId;
		list<Cleaner> cleanerList;

	public:
		Company(int companyId, string password, string mail);
		int getCompanyId();
		void setCompanyId(int companyId);
		list<Cleaner> getCleanerList();
		void addCleaner(Cleaner* cleaner);

};

#endif
