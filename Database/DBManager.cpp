#include <iostream>
#include <map>
#include <unordered_map>
#include "CSVParser.h"
#include "DBManager.h"
#include "../Model/User.h"
#include "../Model/Individual.h"
#include "../Model/Company.h"
#include "../Model/Sensor.h"
#include "../Model/Cleaner.h"
#include "../Model/Measurement.h"
#include "../Model/Reading.h"

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

	string eof;
	string sUserID;
	string sSensorID;
	string sCleanerID;
	string sAttributeID;
	float latitude;
	float longitude;

	// Final Data Structures
	unordered_map<string, User*> users; // Final map<userEmail, User>
	unordered_map<int, Sensor*> sensors; // Final map<sensorID, Sensor>
	unordered_map<int, Cleaner*> cleaners; // Final map<cleanerID, Cleaner>

	/*
	Read through users.csv, create and store the Users found within
	as well as their corresponding sensors
	*/
	unordered_map<int, Individual*> sensorIndividualAssociations; // Temporary association map<sensorID, Individual>
	// CSV Reader
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> usersReader("Dataset/users.csv");
	usersReader.set_header("userID", "sensorID", "EOF");
	// For each row in the CSV...
	while (usersReader.read_row(sUserID, sSensorID, eof)) {
		// Extract integer ids
		int userID = atoi(sUserID.erase(0, 4).c_str());
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// If there's no entry with the ID in the users map, create it
		Individual* individual;
		if (users.count(sUserID) == 0) {
			individual = new Individual(userID, sUserID, ""); // temporary email = userID string
		}
		else {
			individual = (Individual*)users[sUserID];
		}
		// Add data to the temporary association map
		sensorIndividualAssociations[sensorID] = individual;
		// Save it to the users list
		users[sUserID] = individual;
	}

	/*
	Read through sensors.csv, create and store the Sensors found within
	and fetch their owner from the previously created association map
	*/
	// CSV Reader
	io::CSVReader<4, io::trim_chars<>, io::no_quote_escape<';'>> sensorsReader("Dataset/sensors.csv");
	sensorsReader.set_header("sensorID", "latitude", "longitude", "EOF");
	// For each row in the CSV...
	while (sensorsReader.read_row(sSensorID, latitude, longitude, eof)) {
		// Extract integer ids
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// Create the Sensor
		Sensor* sensor = new Sensor(sensorID, latitude, longitude);
		// Fetch owner from association map and set it
		Individual* owner = sensorIndividualAssociations[sensorID];
		sensor->setOwner(owner);
		owner->addSensor(sensor);
		// Save it to the sensors list
		sensors[sensorID] = sensor;
	}

	/*
	Read through providers.csv, create and store the Users found within
	as well as their corresponding cleaners
	*/
	// Data structures
	unordered_map<int, Company*> cleanerCompanyAssociations; // Temporary association map<cleanerID, Company>
	// CSV Reader
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> providersReader("Dataset/providers.csv");
	providersReader.set_header("userID", "sensorID", "EOF");
	// For each row in the CSV...
	while (providersReader.read_row(sUserID, sCleanerID, eof)) {
		// Extract integer ids
		int userID = atoi(sUserID.erase(0, 4).c_str());
		int cleanerID = atoi(sCleanerID.erase(0, 6).c_str());
		// If there's no entry with the ID in the users map, create it
		Company* company;
		if (users.count(sUserID) == 0) {
			company = new Company(userID, sUserID, ""); // temporary email = userID string
		}
		else {
			company = (Company*)users[sUserID];
		}
		// Add data to the temporary association map
		cleanerCompanyAssociations[cleanerID] = company;
		// Save it to the users list
		users[sUserID] = company;
	}

	/*
	Read through cleaners.csv, create and store the Cleaners found within
	and fetch their owner from the previously created association map
	*/
	// CSV Reader
	io::CSVReader<6, io::trim_chars<>, io::no_quote_escape<';'>> cleanersReader("Dataset/cleaners.csv");
	cleanersReader.set_header("cleanerID", "latitude", "longitude", "startTime", "stopTime", "EOF");
	// For each row in the CSV...
	string sStartTime; string sStopTime;
	while (cleanersReader.read_row(sCleanerID, latitude, longitude, sStartTime, sStopTime, eof)) {
		// Extract integer ids
		int cleanerID = atoi(sCleanerID.erase(0, 7).c_str());
		// Extract dates
		Date startTime; Date stopTime; // TODO
		// Create the Cleaner
		Cleaner* cleaner = new Cleaner(cleanerID, latitude, longitude, startTime, stopTime);
		// Fetch owner from association map and set it
		Company* owner = cleanerCompanyAssociations[cleanerID];
		cleaner->setOwner(owner);
		owner->addCleaner(cleaner);
		// Save it to the cleaners list
		cleaners[cleanerID] = cleaner;
	}

	/*
	Read through attributes.csv, store them in an association map
	*/
	unordered_map<string, pair<string, string>> attributesAssociations;
	// CSV Reader
	io::CSVReader<4, io::trim_chars<>, io::no_quote_escape<';'>> attributesReader("Dataset/attributes.csv");
	attributesReader.read_header(io::ignore_missing_column, "attributeID", "unit", "description", "EOF");
	// For each row in the CSV...
	string unit; string description;
	while (attributesReader.read_row(sAttributeID, unit, description, eof)) {
		// Add data to the temporary association map
		attributesAssociations[sAttributeID] = make_pair(unit, description);
	}

	/*
	Read through measurements.csv, create and store the Measurements found within grouped by timestamps
	and fetch their attributes from the previously created association map
	*/
	// CSV Reader
	io::CSVReader<5, io::trim_chars<>, io::no_quote_escape<';'>> measurementsReader("Dataset/measurements.csv");
	measurementsReader.set_header("timestamp", "sensorID", "attributeID", "value", "EOF");
	// For each row in the CSV...
	string sTimestamp; float value;
	while (measurementsReader.read_row(sTimestamp, sSensorID, sAttributeID, value, eof)) {
		// Extract integer ids
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// Extract dates
		Date timestamp; // TODO
		// Create the Measurement
		pair<string, string> attributes = attributesAssociations[sAttributeID];
		Measurement* measurement = new Measurement(attributes.first, attributes.second, value);
		// Add it to a reading corresponding to the correct timestamp
		// TODO
		// Save reading to the corresponding sensor's list
		// TODO
	}

	//DEBUG delete instances
	for(auto u : users) {
		delete u.second;
	}
	for(auto s : sensors) {
		delete s.second;
	}
	for(auto c : cleaners) {
		delete c.second;
	}

}

void DBManager::importLocalData() {
	// TODO - implement DBManager::importLocalData
	throw "Not yet implemented";
}

void DBManager::saveLocalData() {
	// TODO - implement DBManager::saveLocalData
	throw "Not yet implemented";
}
