#include <iostream>
#include <map>
#include "CSVParser.h"
#include "DBManager.h"
#include "../Model/User.h"
#include "../Model/Individual.h"

using namespace std;


string DBManager::getDirectory() {
	return this->directory;
}

void DBManager::setDirectory(string directory) {
	this->directory = directory;
}

void DBManager::importCentralServerData() {
	// TODO - implement DBManager::importCentralServerData
	/*
		A- attributes
		B- cleaners
		C- measurements
		D- providers
		E- sensors
		F- users

		1- liste de users (map, cl� = ...)
		2- liste de sensors (map, cl� = id), potentiellement associ�e � un user
		3- liste de cleaners (map, cl� = id)
		4- liste de readings (map, cl� = timestamp), associ�e � un sensor
		5- liste de measurements (list), associ�e � un reading

		parcours simple de F pour cr�er (1) puis stoquer les valeurs dans une map temporaire (cl� = sensorID, valeurs = users, mais attention � pas cr�er des users dupliqu�es))
		parcours simple de E pour cr�er (2) avec chopage des owners dans la map cr�e pr�cedemment
		parcours de D pour stoquer les valeurs dans une map temporaire (cl� = cleanerID)
		parcours simple de B pour cr�er (3) avec chopage des providers depuis la map cr�e p�cedemment
		parcours de A pour stoquer les valeurs dans une map temporaire (scope de la fonction) (cl� = id)
		parcours de measurements, cr�ation des Measurements avec les attributs tir�s de la map cr�e pr�cedemment
		regroupement de 4 Measurements cons�cutifs (m�me timestamp) en (5) stoqu�e dans un Reading puis ajout � (4) avec association � un sensor de (2)
	*/

	/* Read through the users.csv and create the existing Users */
	std::map<int, User*> users; //(userID, User)
	std::map<int, User*> sensorUsersAssociation; //(sensorID, User)
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> in("../Dataset/users.csv");
	in.set_header("userID", "sensorID", "EOF");
	string sUserID; string sSensorID; string eof;
	while (in.read_row(sUserID, sSensorID, eof)) {
		// Extract integer ids
		int userID = atoi(sUserID.erase(0, 4).c_str());
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// If there's no entry with the ID in the users map, create a User
		if (users.count(userID) == 0) {
			users[userID] = new  Individual(userID, "", "");
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

void DBManager::importLocalData() {
	// TODO - implement DBManager::importLocalData
	throw "Not yet implemented";
}

void DBManager::saveLocalData() {
	// TODO - implement DBManager::saveLocalData
	throw "Not yet implemented";
}

int main() {

	DBManager dbManager;
	dbManager.importCentralServerData();

	return 0;

}
