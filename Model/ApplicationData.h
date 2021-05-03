#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

namespace Model {
	class ApplicationData {

	private:
		List cleanerList;
		List sensorList;
		List userList;

	public:
		List getCleanerList();

		void addCleaner(Model::Cleaner cleaner);

		List getSensorList();

		void addSensor(Model::Sensor sensor);

		List getUserList();

		void addUser(Model::User user);

		float distance(float lat1, float lon1, float lat2, float lon2);
	};
}

#endif
