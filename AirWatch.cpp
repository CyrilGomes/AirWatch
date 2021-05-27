#include <iostream>
using namespace std;

#include "Model/ApplicationData.h"
#include "Display/HMIManager.h"
#include "Services/UserServices.h"
#include "Services/ApplicationServices.h"
#include"Test/Test.h"
int main(int argc, char const *argv[])
{
    // Import data from central and local server
    //ApplicationServices::importData();

    #ifdef DEBUG
        // DEBUG: print data
        ApplicationData *applicationData = ApplicationData::getInstance();
        cout << "\n-> User List: " << endl;
        auto userList = applicationData->getUserList();
        for (auto i : userList)
        {
            User *u = i.second;
            cout << u->getType() << "; " << u->getId() << "; " << u->getMail() << "; " << u->getPassword() << endl;
        }
        cout << "\n-> Sensor List: " << endl;
        auto sensorList = applicationData->getSensorList();
        for (auto i : sensorList)
        {
            Sensor *s = i.second;
            cout << i.first << ": " << s->getLatitude() << "; " << s->getLongitude() << "; " << s->getReadings().size() << " readings" << endl;
        }
        cout << "\n-> Cleaner List: " << endl;
        auto cleanerList = applicationData->getCleanerList();
        for (auto i : cleanerList)
        {
            Cleaner *c = i.second;
            cout << i.first << ": " << c->getLatitude() << "; " << c->getLongitude() << endl;
        }
        cout << "\n-> ATMO check on sensor 80: " << endl;
        Sensor *s0 = sensorList[80];
        auto sensorReadings = s0->getReadings();
        for (auto i : sensorReadings)
        {
            cout << i.second->getTimeStamp() << ": " << i.second->atmo() << endl;
            auto measurements = i.second->getMeasurements();
            for (auto j : measurements)
            {
                cout << "* " << j.first << ": " << j.second->getValue() << endl;
            }
        }
        cout << endl;
    #endif


    #ifdef TEST
        Test test;
        test.test();


        return 0;
    #endif
    // Launch the display
    HMIManager hmi;
    hmi.loginMenu();

    // At the end of execution, save local data and clean up
    ApplicationServices::saveData();
    ApplicationServices::cleanup();

    return 0;
}
