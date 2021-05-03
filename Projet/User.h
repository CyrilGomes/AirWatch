#ifndef USER_H
#define USER_H

namespace Model {
	class User {

	protected:
		int id;
		String password;
		String mail;

	public:
		int getId();

		void setId(int id);

		String getPassword();

		void setPassword(String password);

		String getMail();

		void setMail(String mail);

		User(int id, String password, String mail);
	};
}

#endif
