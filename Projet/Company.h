#ifndef COMPANY_H
#define COMPANY_H

namespace Model {
	class Company : Model::User {

	private:
		int companyId;
		List cleanerList;

	public:
		Company(int id, String password, String mail, int companyId);

		int getCompanyId();

		void setCompanyId(int companyId);

		List getCleanerList();

		void setCleanerList(List cleanerList);
	};
}

#endif
