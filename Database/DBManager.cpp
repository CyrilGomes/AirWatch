#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include "CSVParser.h"
#include "MagicEnum.hpp"
#include "DBManager.h"
#include "../Model/User.h"
#include "../Model/Sensor.h"
#include "../Model/Cleaner.h"
#include "../Model/Measurement.h"
#include "../Model/Reading.h"
#include "../Model/ApplicationData.h"
using namespace std;

DBManager::DBManager(string directory) : directory(directory) {
}

string DBManager::getDirectory() {
	return this->directory;
}

void DBManager::setDirectory(string directory) {
	this->directory = directory;
}

void DBManager::importCentralServerData() {

	// Main reading buffer variables
	string eof;
	string sUserID;
	string sSensorID;
	string sCleanerID;
	string sAttributeID;
	float latitude;
	float longitude;

	// ApplicationData instance
	ApplicationData* applicationData = ApplicationData::getInstance();

	/*
	Read through users.csv, create and store the Users found within
	as well as their corresponding sensors
	*/
	unordered_map<int, Individual*> sensorIndividualAssociations; // Temporary association map<sensorID, Individual>
	// CSV Reader
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> usersReader(directory + "Central/users.csv");
	usersReader.set_header("userID", "sensorID", "EOF");
	// For each row in the CSV...
	while (usersReader.read_row(sUserID, sSensorID, eof)) {
		// Extract integer ids
		string fUserID = sUserID;
		int userID = atoi(sUserID.erase(0, 4).c_str());
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// If there's no entry with the ID in the users map, create it
		Individual* individual;
		unordered_map<string, User*> userList = applicationData->getUserList();
		if (userList.count(fUserID) == 0) {
			individual = new Individual(userID, fUserID, ""); // temporary email = userID string
		}
		else {
			individual = (Individual*)userList[fUserID];
		}
		// Add data to the temporary association maps
		sensorIndividualAssociations[sensorID] = individual;
		individualsMap[userID] = individual; //map that speeds up importLocalData()
		// Save it to the users list
		applicationData->addUser(individual);
	}

	/*
	Read through sensors.csv, create and store the Sensors found within
	and fetch their owner from the previously created association map
	*/
	// CSV Reader
	io::CSVReader<4, io::trim_chars<>, io::no_quote_escape<';'>> sensorsReader(directory + "Central/sensors.csv");
	sensorsReader.set_header("sensorID", "latitude", "longitude", "EOF");
	// For each row in the CSV...
	while (sensorsReader.read_row(sSensorID, latitude, longitude, eof)) {
		// Extract integer ids
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// Create the Sensor
		Sensor* sensor = new Sensor(sensorID, latitude, longitude);
		// Fetch owner from association map and set it
		Individual* owner = sensorIndividualAssociations[sensorID];
		if (owner != nullptr) {
			sensor->setOwner(owner);
			owner->addSensor(sensor);
		}
		// Save it to the sensors list
		applicationData->addSensor(sensor);
	}

	/*
	Read through providers.csv, create and store the Users found within
	as well as their corresponding cleaners
	*/
	// Data structures
	unordered_map<int, Company*> cleanerCompanyAssociations; // Temporary association map<cleanerID, Company>
	// CSV Reader
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> providersReader(directory + "Central/providers.csv");
	providersReader.set_header("userID", "sensorID", "EOF");
	// For each row in the CSV...
	while (providersReader.read_row(sUserID, sCleanerID, eof)) {
		// Extract integer ids
		string fUserID = sUserID;
		int userID = atoi(sUserID.erase(0, 8).c_str());
		int cleanerID = atoi(sCleanerID.erase(0, 7).c_str());
		// If there's no entry with the ID in the users map, create it
		Company* company;
		unordered_map<string, User*> userList = applicationData->getUserList();
		if (userList.count(fUserID) == 0) {
			company = new Company(userID, fUserID, ""); // temporary email = userID string
		}
		else {
			company = (Company*)userList[fUserID];
		}
		// Add data to the temporary association map
		cleanerCompanyAssociations[cleanerID] = company;
		companiesMap[userID] = company; //map that speeds up importLocalData()
		// Save it to the users list
		applicationData->addUser(company);
	}

	/*
	Read through cleaners.csv, create and store the Cleaners found within
	and fetch their owner from the previously created association map
	*/
	// CSV Reader
	io::CSVReader<6, io::trim_chars<>, io::no_quote_escape<';'>> cleanersReader(directory + "Central/cleaners.csv");
	cleanersReader.set_header("cleanerID", "latitude", "longitude", "startTime", "stopTime", "EOF");
	// For each row in the CSV...
	Date startTime; Date stopTime;
	while (cleanersReader.read_row(sCleanerID, latitude, longitude, startTime, stopTime, eof)) {
		// Extract integer ids
		int cleanerID = atoi(sCleanerID.erase(0, 7).c_str());
		// Create the Cleaner
		Cleaner* cleaner = new Cleaner(cleanerID, latitude, longitude, startTime, stopTime);
		// Fetch owner from association map and set it
		Company* owner = cleanerCompanyAssociations[cleanerID];
		if (owner != nullptr) {
			cleaner->setOwner(owner);
			owner->addCleaner(cleaner);
		}
		// Save it to the cleaners list
		applicationData->addCleaner(cleaner);
	}

	/*
	Read through attributes.csv, store them in an association map
	*/
	unordered_map<string, pair<string, string>> attributesAssociations;
	// CSV Reader
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> attributesReader(directory + "Central/attributes.csv");
	attributesReader.read_header(io::ignore_extra_column, "AttributeID", "Unit", "Description");
	// For each row in the CSV...
	string unit; string description;
	while (attributesReader.read_row(sAttributeID, unit, description)) {
		// Add data to the temporary association map
		attributesAssociations[sAttributeID] = make_pair(unit, description);
	}

	/*
	Read through measurements.csv, create and store the Measurements found within grouped by timestamps
	and fetch their attributes from the previously created association map
	*/
	// CSV Reader
	io::CSVReader<5, io::trim_chars<>, io::no_quote_escape<';'>> measurementsReader(directory + "Central/measurements.csv");
	measurementsReader.set_header("timestamp", "sensorID", "attributeID", "value", "EOF");
	// For each row in the CSV...
	Reading* currentReading;
	Date previousTimeStamp; previousTimeStamp.setYear(-1);
	Date timeStamp; float value;
	while (measurementsReader.read_row(timeStamp, sSensorID, sAttributeID, value, eof)) {
		// Extract integer ids
		int sensorID = atoi(sSensorID.erase(0, 6).c_str());
		// Create the Measurement
		pair<string, string> attributes = attributesAssociations[sAttributeID];
		Measurement* measurement = new Measurement(attributes.first, attributes.second, value);
		// Add it to a reading corresponding to the correct timestamp
		if (!(timeStamp == previousTimeStamp)) {
			currentReading = new Reading(timeStamp);
			previousTimeStamp = timeStamp;
		}
		currentReading->addMeasurement(measurement, sAttributeID);
		// Save reading to the corresponding sensor's list
		Sensor* sensor = applicationData->getSensorList()[sensorID];
		currentReading->setSensor(sensor);
		sensor->addReading(currentReading);
	}

}

void DBManager::importLocalData() {

	// ApplicationData instance
	ApplicationData* applicationData = ApplicationData::getInstance();

	/*
	Read through logins.csv, create and store the Users found within unless they already exist in individualsMap/companiesMap,
	in which case update their email and password and change their userList map key.
	If the user is an individual, add it to individualsMap for the next step
	*/
	// CSV Reader
	io::CSVReader<4, io::trim_chars<>, io::no_quote_escape<';'>> loginsReader(directory + "Local/logins.csv");
	loginsReader.read_header(io::ignore_extra_column, "userType", "id", "mail", "password");
	// For each row in the CSV...
	string userType; int id; string mail; string password;
	while (loginsReader.read_row(userType, id, mail, password)) {
		User* user;
		UserType type = (magic_enum::enum_cast<UserType>(userType)).value();
		// If the user already exists in individualsMap, fetch it from there
		if (individualsMap.count(id) != 0 && type == UserType::individual) {
			user = individualsMap[id];
			// Delete old key, update attributes, save new key
			string oldMail = user->getMail();
			user->setMail(mail);
			user->setPassword(password);
			if (oldMail != mail) {
				applicationData->updateUserList(oldMail);
			}
		}
		// If the user already exists in companiesMap, fetch it from there
		else if (companiesMap.count(id) != 0 && type == UserType::company) {
			user = companiesMap[id];
			// Delete old key, update attributes, save new key
			string oldMail = user->getMail();
			user->setMail(mail);
			user->setPassword(password);
			if (oldMail != mail) {
				applicationData->updateUserList(oldMail);
			}
		}
		// Otherwise, create it depending on its type
		else {
			//UserType type = (magic_enum::enum_cast<UserType>(userType)).value();
			switch(type) {
				case UserType::government:
					user = new Government(mail, password);
					break;
				case UserType::company:
					user = new Company(id, mail, password);
					break;
				case UserType::individual:
					user = new Individual(id, mail, password);
					// If it's an indivudual, save it to the individualsMap
					individualsMap[id] = (Individual*)user;
					break;
			}
			applicationData->addUser(user);
		}
	}

	/*
	Read through individuals.csv, fetch Individual from individualsMap,
	and update its attributes
	*/
	// CSV Reader
	io::CSVReader<3, io::trim_chars<>, io::no_quote_escape<';'>> individualsReader(directory + "Local/individuals.csv");
	individualsReader.read_header(io::ignore_extra_column, "id", "points", "flag");
	// For each row in the CSV...
	int points; string userFlag;
	while (individualsReader.read_row(id, points, userFlag)) {
		// Fetch individual from individualsMap
		Individual* individual = individualsMap[id];
		// Update its attributes
		ReliabilityFlag flag = (magic_enum::enum_cast<ReliabilityFlag>(userFlag)).value();
		individual->setPoints(points);
		individual->setReliabilityFlag(flag);
	}

}

void DBManager::saveLocalData() {

	// ApplicationData instance
	ApplicationData* applicationData = ApplicationData::getInstance();
	unordered_map<string, User*> userList = applicationData->getUserList();

	// Open csv files
	ofstream loginsCsv;
	ofstream individualsCsv;
	loginsCsv.open(directory + "Local/logins.csv");
	individualsCsv.open(directory + "Local/individuals.csv");

	// Headers
	loginsCsv << "userType;id;mail;password" << endl;
	individualsCsv << "id;points;flag" << endl;

	// Loop through all the users
	for (pair<string, User*> i : userList) {
		// Fetch user info
		User* user = i.second;
		string type = (string)magic_enum::enum_name(user->getType());
		unsigned int id = user->getId();
		string mail = user->getMail();
		string password = user->getPassword();
		// Write it in the first csv
		loginsCsv << type << ";" << id << ";" << mail << ";" << password << endl;
		// In the case of an individual:
		if (user->getType() == UserType::individual) {
			// Fetch individual info
			Individual* individual = (Individual*)user;
			int points = individual->getPoints();
			string flag = (string)magic_enum::enum_name(individual->getReliabilityFlag());
			// Write it in the second csv
			individualsCsv << id << ";" << points << ";" << flag << endl;
		}
	}

	// Close files
	loginsCsv.close();
	individualsCsv.close();

}
