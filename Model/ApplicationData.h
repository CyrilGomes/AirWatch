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
		static ApplicationData* getInstance();
		unordered_map<int, Cleaner*> getCleanerList();
		void addCleaner(Cleaner* cleaner);
		unordered_map<int, Sensor*> getSensorList();
		void addSensor(Sensor* sensor);
		unordered_map<string, User*> getUserList();
		void addUser(User* user);
		void updateUserList(string oldKey);
		static float distance(float lat1, float lon1, float lat2, float lon2);
		~ApplicationData();
		ApplicationData(ApplicationData& other) = delete;
    	void operator = (const ApplicationData& other) = delete;
};

#endif
