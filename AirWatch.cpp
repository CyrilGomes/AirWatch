#include <iostream>
using namespace std;

#include "Database/DBManager.h"
#include "Model/ApplicationData.h"
#include "Display/DisplayManager.h"
#include "Services/UserManagement.h"

int main(int argc, char const *argv[])
{
    // Import data from central and local server
    DBManager dbManager("Dataset/");
    dbManager.importCentralServerData();
    dbManager.importLocalData();

    // DEBUG: print data
    ApplicationData* applicationData = ApplicationData::getInstance();
    cout << "-> User List: " << endl;
    auto userList = applicationData->getUserList();
    for (auto i : userList) {
        User* u = i.second;
        cout << u->getType() << "; " << u->getId() << "; " << u->getMail() << "; " << u->getPassword() << endl;
    }
    cout << "-> Sensor List: " << endl;
    auto sensorList = applicationData->getSensorList();
    for (auto i : sensorList) {
        Sensor* s = i.second;
        cout << i.first << ": " << s->getLatitude() << "; " << s->getLongitude() << "; " << s->getReadings().size() << " readings" << endl;
    }
    cout << "-> Cleaner List: " << endl;
    auto cleanerList = applicationData->getCleanerList();
    for (auto i : cleanerList) {
        Cleaner* c = i.second;
        cout << i.first << ": " << c->getLatitude() << "; " << c->getLongitude() << endl;
    }

    // DEBUG: Using main menu
    DisplayManager displayManager;
    displayManager.loginMenu();

    // Save local data
    dbManager.saveLocalData();

    // Clean up
    delete applicationData;

    return 0;
}
