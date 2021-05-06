#include "DisplayManager.h"
#include "Console.h"
#include "../Model/User.h"
#include "../Services/UserManagement.h"

#include <iostream>
using namespace std;

// Menu displays
int DisplayManager::promptMenuChoice(string prompt, vector<pair<string, function<void()>>> menuItems) {

    cout << prompt << " :" << endl;
    int count = 1;
    for (pair<string, function<void()>> item : menuItems)
    {
        cout << count << ". " << item.first << endl;
        count++;
    }
    return Console::promptInteger(">");

}

void DisplayManager::displayLoginMenu()
{
    vector<pair<string, function<void()>>> optionsList = {
        pair<string, function<void()>>("Login", bind(&DisplayManager::queryLogin, this)),
        pair<string, function<void()>>("Register", bind(&DisplayManager::queryIndividualRegister, this))
    };

    optionsList[promptMenuChoice("WELCOME TO AIRWATCH:", optionsList) - 1].second();
}

void DisplayManager::displayMainMenu()
{
    User currentUser = UserManagement::getCurrentUser();

    vector<pair<string, function<void()>>> optionsList;

    optionsList.insert(optionsList.end(), pair<string, function<void()>>("Sensor analytics", bind(&DisplayManager::displaySensorMenu, this)));
    optionsList.insert(optionsList.end(), pair<string, function<void()>>("Cleaner analytics", bind(&DisplayManager::queryCleanerContribution, this)));

    UserType userType = currentUser.getType();
    switch (userType)
    {
    case UserType::company:
        optionsList.insert(optionsList.end(), pair<string, function<void()>>("Register Air Cleaning Company", bind(&DisplayManager::queryCompanyRegister, this)));
        break;

    case UserType::individual:
        optionsList.insert(optionsList.end(), pair<string, function<void()>>("My user points", bind(&DisplayManager::queryIndividualPoints, this)));
        break;
    }

    optionsList.insert(optionsList.end(), pair<string, function<void()>>("Log out", bind(&DisplayManager::queryLogout, this)));

    optionsList[promptMenuChoice("Main menu:", optionsList) - 1].second();
}

void DisplayManager::displaySensorMenu()
{
}

// Sensor queries
void DisplayManager::querySensorReliability()
{
}

void DisplayManager::querySensorFlag()
{
}

void DisplayManager::querySensorSimilarity()
{
}

void DisplayManager::queryAreaAirQuality()
{
}

void DisplayManager::queryPunctualAirQuality()
{
}

// Cleaner queries
void DisplayManager::queryCleanerContribution()
{
}

// User queries
void DisplayManager::queryIndividualPoints()
{
}

void DisplayManager::queryLogin()
{
}

void DisplayManager::queryLogout()
{
}

void DisplayManager::queryIndividualRegister()
{
}

void DisplayManager::queryCompanyRegister()
{
}
