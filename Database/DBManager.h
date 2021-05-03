#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <string>
using namespace std;

class DBManager {

	private:
		string directory;

	public:
		string getDirectory();
		void setDirectory(string directory);
		void importCentralServerData();
		void importLocalData();
		void saveLocalData();

};

#endif
