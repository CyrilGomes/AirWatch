#ifndef COMPANY_H
#define COMPANY_H

#include <list>
#include <string>
using namespace std;

#include "User.h"
#include "Cleaner.h"

	class Company : User {

		private:
			int companyId;
			list<Cleaner> cleanerList;

		public:
			Company(int id, string password, string mail, int companyId);

			int getCompanyId();

			void setCompanyId(int companyId);

			list<Cleaner> getCleanerList();

			void setCleanerList(list<Cleaner> cleanerList);
	};

#endif
