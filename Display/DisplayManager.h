#ifndef DISPLAYMANAGEMENT_H
#define DISPLAYMANAGEMENT_H

#include <vector>
#include <string>
#include <functional>
using namespace std;

class DisplayManager {
    public:
        // Menu displays
        void displayMenu(string menuTitle, vector<pair<string, function<void()>>> optionsList);
        void loginMenu();
        void mainMenu();
        void sensorMenu();

        // Sensor queries
        void querySensorReliability();
        void querySensorFlag();
        void querySensorSimilarity();
        void queryAreaAirQuality();
        void queryPunctualAirQuality();

        // Cleaner queries
        void queryCleanerContribution();

        // User queries
        void queryIndividualPoints();
        void queryLogin();
        void queryLogout();
        void queryIndividualRegister();
        void queryCompanyRegister();
};

#endif
