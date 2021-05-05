#ifndef DISPLAYMANAGEMENT_H
#define DISPLAYMANAGEMENT_H

#include <string>
#include <list>
using namespace std;

class DisplayManager {
    public:
        // Menu displays
        static void displayLoginMenu();
        static void displayMainMenu();
        static void displaySensorMenu();

        // Sensor queries
        static void querySensorReliability();
        static void querySensorFlag();
        static void querySensorSimilarity();
        static void queryAreaAirQuality();
        static void queryPunctualAirQuality();

        // Cleaner queries
        static void queryCleanerContribution();

        // User queries
        static void queryIndividualPoints();
        static void queryLogin();
        static void queryLogout();
        static void queryIndividualRegister();
        static void queryCompanyRegister();
};

#endif
