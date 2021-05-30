#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

#include <map>
#include <unordered_map>
#include "Cleaner.h"
#include "Sensor.h"
#include "User.h"
using namespace std;

class ApplicationData {

	private:
		unordered_map<int, Cleaner*> cleanerList;
		unordered_map<int, Sensor*> sensorList;
		unordered_map<string, User*> userList;
		static ApplicationData* singleton;
		ApplicationData();

	public:
		/* CONSTRUCTORS & DESTRUCTOR ---------------------------------------- */
		ApplicationData(ApplicationData& other) = delete;
		~ApplicationData();
		/* ACCESSORS -------------------------------------------------------- */
		static ApplicationData* getInstance();
		unordered_map<int, Cleaner*> getCleanerList() const;
		void addCleaner(Cleaner* cleaner);
		unordered_map<int, Sensor*> getSensorList() const;
		void addSensor(Sensor* sensor);
		unordered_map<string, User*> getUserList() const;
		void addUser(User* user);
		/* METHODS ---------------------------------------------------------- */
		void updateUserList(string oldKey);
		/* OPERATOR OVERLOADS ----------------------------------------------- */
    	void operator = (const ApplicationData& other) = delete;
		
};

#endif
