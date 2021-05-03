#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

class ApplicationData {

	private:
		list cleanerList;
		list sensorList;
		list userList;

	public:
		list getCleanerList();

		void addCleaner(Cleaner cleaner);

		list getSensorList();

		void addSensor(Sensor sensor);

		list getUserList();

		void addUser(User user);

		float distance(float lat1, float lon1, float lat2, float lon2);
};

#endif
