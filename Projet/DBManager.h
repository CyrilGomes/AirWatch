#ifndef DBMANAGER_H
#define DBMANAGER_H

namespace Database {
	class DBManager {

	private:
		String directory;

	public:
		String getDirectory();

		void setDirectory(String directory);

		void importCentralServerData();

		void importLocalData();

		void saveLocalData();
	};
}

#endif
