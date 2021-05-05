#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <string>
#include <unordered_map>
#include "../Model/Individual.h"
#include "../Model/Company.h"
#include "../Model/Government.h"
using namespace std;

class DBManager {

	private:
		string directory;
		unordered_map<int, Individual*> individualsMap;
		unordered_map<int, Company*> companiesMap;

	public:
		DBManager(string directory);
		string getDirectory();
		void setDirectory(string directory);
		void importCentralServerData();
		void importLocalData();
		void saveLocalData();

};

#endif
