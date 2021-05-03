#include "DBManager.h"

String Database::DBManager::getDirectory() {
	return this->directory;
}

void Database::DBManager::setDirectory(String directory) {
	this->directory = directory;
}

void Database::DBManager::importCentralServerData() {
	// TODO - implement DBManager::importCentralServerData
	throw "Not yet implemented";
}

void Database::DBManager::importLocalData() {
	// TODO - implement DBManager::importLocalData
	throw "Not yet implemented";
}

void Database::DBManager::saveLocalData() {
	// TODO - implement DBManager::saveLocalData
	throw "Not yet implemented";
}
