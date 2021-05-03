#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

#include <list>
#include "Cleaner.h"
#include "Sensor.h"
#include "User.h"
using namespace std;

class ApplicationData {

	private:
		list<Cleaner> cleanerList;
		list<Sensor> sensorList;
		list<User> userList;

	public:
		list<Cleaner> getCleanerList();
		void addCleaner(Cleaner cleaner);
		list<Sensor> getSensorList();
		void addSensor(Sensor sensor);
		list<User> getUserList();
		void addUser(User user);
		float distance(float lat1, float lon1, float lat2, float lon2);

};

#endif
