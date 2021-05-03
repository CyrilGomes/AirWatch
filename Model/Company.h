#ifndef COMPANY_H
#define COMPANY_H

class Company : User {

	private:
		int companyId;
		list cleanerList;

	public:
		Company(int id, string password, string mail, int companyId);

		int getCompanyId();

		void setCompanyId(int companyId);

		list getCleanerList();

		void setCleanerList(list cleanerList);
};

#endif
