#ifndef DBMANAGER_H
#define DBMANAGER_H

namespace Database {
	class DBManager {

	private:
		std::string directory;

	public:
		std::string getDirectory();

		void setDirectory(std::string directory);

		void importCentralServerData();

		void importLocalData();

		void saveLocalData();
	};
}

#endif
