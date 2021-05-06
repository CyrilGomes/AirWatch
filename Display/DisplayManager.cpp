#include "DisplayManager.h"
#include "Console.h"
#include "../Model/User.h"
#include "../Services/UserManagement.h"

#include <iostream>
using namespace std;

typedef pair<string, function<void()>> Option;

// Menu displays
int DisplayManager::promptMenuChoice(string prompt, vector<Option> menuItems) {

    cout << prompt << " :" << endl;
    int count = 1;
    for (Option item : menuItems)
    {
        cout << count << ". " << item.first << endl;
        count++;
    }
    return Console::promptInteger(">");
}

void DisplayManager::displayLoginMenu()
{
    const string menuTitle = "WELCOME TO AIRWATCH";

    vector<Option> optionsList = {
        Option("Login", bind(&DisplayManager::queryLogin, this)),
        Option("Register", bind(&DisplayManager::queryIndividualRegister, this))
    };

    optionsList[promptMenuChoice(menuTitle, optionsList) - 1].second();
}

void DisplayManager::displayMainMenu()
{
    const string menuTitle = "Main menu:";

    vector<Option> optionsList{
        Option("Sensor analytics", bind(&DisplayManager::displaySensorMenu, this)),
        Option("Cleaner analytics", bind(&DisplayManager::queryCleanerContribution, this)),
        Option("Log out", bind(&DisplayManager::queryLogout, this))
    };

    User currentUser = UserManagement::getCurrentUser();
    UserType userType = currentUser.getType();
    switch (userType)
    {
    case UserType::company:
        optionsList.insert(optionsList.end() - 1, Option("Register Air Cleaning Company", bind(&DisplayManager::queryCompanyRegister, this)));
        break;

    case UserType::individual:
        optionsList.insert(optionsList.end() - 1, Option("My user points", bind(&DisplayManager::queryIndividualPoints, this)));
        break;
    }

    optionsList[promptMenuChoice(menuTitle, optionsList) - 1].second();
}

void DisplayManager::displaySensorMenu()
{
    const string menuTitle = "Sensor analytics menu:";

    vector<Option> optionsList = {
        Option("Get the air quality of a given location", bind(&DisplayManager::queryPunctualAirQuality, this)),
        Option("Get the air quality of a given area", bind(&DisplayManager::queryAreaAirQuality, this)),
        Option("See sensor reliabilities", bind(&DisplayManager::querySensorReliability, this)),
        Option("Find data similarities", bind(&DisplayManager::querySensorSimilarity, this)),
        Option("Go back", bind(&DisplayManager::displayMainMenu, this))
    };

    optionsList[promptMenuChoice(menuTitle, optionsList) - 1].second();
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
