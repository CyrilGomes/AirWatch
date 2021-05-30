#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <string>
#include <unordered_map>
#include "../Model/User.h"
#include "../Model/Individual.h"
#include "../Model/Company.h"
#include "../Model/Government.h"
using namespace std;

class DBManager {

	private:
		static string directory;

	public:
		/* ACCESSORS */
		static string getDirectory();
		static void setDirectory(string directory);
		/* METHODS */
		static void importCentralAndLocalData();
		static void saveLocalData();
		static void updateLocalDataWithUser(User* newUser);

};

#endif
