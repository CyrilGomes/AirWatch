#include <iostream>
#include <map>
#include "CSVParser.h"
#include "DBManager.h"
#include "../Model/User.h"
#include "../Model/Individual.h"

using namespace std;
using namespace Database;

string Database::DBManager::getDirectory() {
	return this->directory;
}

void Database::DBManager::setDirectory(string directory) {
	this->directory = directory;
}

void Database::DBManager::importCentralServerData() {
	// TODO - implement DBManager::importCentralServerData
	/*
		A- attributes
		B- cleaners
		C- measurements
		D- providers
		E- sensors
		F- users

		1- liste de users (map, clé = ...)
		2- liste de sensors (map, clé = id), potentiellement associée à un user
		3- liste de cleaners (map, clé = id)
		4- liste de readings (map, clé = timestamp), associée à un sensor
		5- liste de measurements (list), associée à un reading

		parcours simple de F pour créer (1) puis stoquer les valeurs dans une map temporaire (clé = sensorID, valeurs = users, mais attention à pas créer des users dupliquées))
		parcours simple de E pour créer (2) avec chopage des owners dans la map crée précedemment
		parcours de D pour stoquer les valeurs dans une map temporaire (clé = cleanerID)
		parcours simple de B pour créer (3) avec chopage des providers depuis la map crée pécedemment
		parcours de A pour stoquer les valeurs dans une map temporaire (scope de la fonction) (clé = id)
		parcours de measurements, création des Measurements avec les attributs tirés de la map crée précedemment
		regroupement de 4 Measurements consécutifs (même timestamp) en (5) stoquée dans un Reading puis ajout à (4) avec association à un sensor de (2)
	*/

	/* Read through the users.csv and create the existing Users */
	std::map<int, Model::User*> users; //(userID, User)
	std::map<int, Model::User*> sensorUsersAssociation; //(sensorID, User)
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> in("../Dataset/users.csv");
	in.set_header("userID", "sensorID", "EOF");
	string sUserID; string sSensorID; string eof;
	while (in.read_row(sUserID, sSensorID, eof)) {
		// Extract integer ids
		int userID = atoi(sUserID.erase(0, 4).c_str());
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// If there's no entry with the ID in the users map, create a User
		if (users.count(userID) == 0) {
			users[userID] = new Individual(userID, "", "");
		}
		// Add it to the temporary map
		sensorUsersAssociation[sensorID] = users[userID];
	}

	//DEBUG delete users
	for(auto u : users) {
		delete u.second;
	}

	//throw "Not yet implemented";
}

void Database::DBManager::importLocalData() {
	// TODO - implement DBManager::importLocalData
	throw "Not yet implemented";
}

void Database::DBManager::saveLocalData() {
	// TODO - implement DBManager::saveLocalData
	throw "Not yet implemented";
}

int main() {

	Database::DBManager dbManager;
	dbManager.importCentralServerData();

	return 0;

}
