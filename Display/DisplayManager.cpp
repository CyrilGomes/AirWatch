#include "DisplayManager.h"
#include "Console.h"
#include "../Model/User.h"
#include "../Model/Individual.h"
#include "../Services/UserServices.h"
#include "../Services/ApplicationServices.h"

#include <iostream>
using namespace std;

typedef pair<string, function<void()>> Option;

// Menu displays
void DisplayManager::displayMenu(string menuTitle, vector<Option> optionsList)
{
    // Display Menu
    cout << menuTitle << " :" << endl;
    int count = 1;
    for (Option item : optionsList)
    {
        cout << count << ". " << item.first << endl;
        count++;
    }

    // Fetch menu choice
    int menuChoice = Console::promptInteger(">") - 1;

    // If choice is not within menu options, retry
    if (menuChoice < 0 || menuChoice >= optionsList.size()) {
        Console::displayMessage("Invalid choice, please try again\n");
        displayMenu(menuTitle, optionsList);
    }
    // Otherwise, execute bound function
    else {
        optionsList[menuChoice].second();
    }
}

void DisplayManager::loginMenu()
{
    const string menuTitle = "WELCOME TO AIRWATCH";

    vector<Option> optionsList = {
        Option("Login", bind(&DisplayManager::queryLogin, this)),
        Option("Register", bind(&DisplayManager::queryIndividualRegister, this))};

    displayMenu(menuTitle, optionsList);
}

void DisplayManager::mainMenu()
{
    const string menuTitle = "Main menu:";

    vector<Option> optionsList{
        Option("Sensor analytics", bind(&DisplayManager::sensorMenu, this)),
        Option("Cleaner analytics", bind(&DisplayManager::queryCleanerContribution, this)),
        Option("Log out", bind(&DisplayManager::queryLogout, this))};

    User currentUser = UserServices::getCurrentUser();
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

    displayMenu(menuTitle, optionsList);
}

void DisplayManager::sensorMenu()
{
    const string menuTitle = "Sensor analytics menu:";

    vector<Option> optionsList = {
        Option("Get the air quality of a given location", bind(&DisplayManager::queryPunctualAirQuality, this)),
        Option("Get the air quality of a given area", bind(&DisplayManager::queryAreaAirQuality, this)),
        Option("See sensor reliabilities", bind(&DisplayManager::querySensorReliability, this)),
        Option("Find data similarities", bind(&DisplayManager::querySensorSimilarity, this)),
        Option("Go back", bind(&DisplayManager::mainMenu, this))};

    displayMenu(menuTitle, optionsList);
}

// Sensor queries
void DisplayManager::querySensorReliability()
{
    // TODO: Add starting time and ending time prompts when done

    ApplicationServices appServices;
    // TODO: Add call to the service

    const string menuTitle = "Sensor analytics menu:";

    User currentUser = UserServices::getCurrentUser();
    UserType userType = currentUser.getType();
    if (userType == UserType::government)
    {
        vector<Option> optionsList = {
            Option("Flag a sensor as unreliable (x)", bind(&DisplayManager::querySensorFlag, this)),
            Option("Flag a sensor as reliable (-)", bind(&DisplayManager::querySensorFlag, this)), // TODO: Change querySensorFlag to queryUnSensorFlag when implemented
            Option("Go back", bind(&DisplayManager::sensorMenu, this))};

        displayMenu(menuTitle, optionsList);
    }
    else
    {
        sensorMenu();
    }
}

void DisplayManager::querySensorFlag()
{
    int sensorId = Console::promptInteger("Sensor ID");

    ApplicationServices appServices;
    appServices.flagSensor(sensorId, false);
}

void DisplayManager::querySensorSimilarity()
{
    int sensorId = Console::promptInteger("Sensor ID");

    // TODO: Add starting time and ending time prompts when done

    ApplicationServices appServices;
    // TODO: Add call to the service
}

void DisplayManager::queryAreaAirQuality()
{
    float latitude = Console::promptFloat("Latitude");
    float longitude = Console::promptFloat("Longitude");
    int radius = Console::promptInteger("Radius (m)");

    // TODO: Add starting time and ending time prompts when done

    ApplicationServices appServices;
    // TODO: Add call to the service
}

void DisplayManager::queryPunctualAirQuality()
{
    float latitude = Console::promptFloat("Latitude");
    float longitude = Console::promptFloat("Longitude");

    // TODO: Add starting time and ending time prompts when done

    ApplicationServices appServices;
    // TODO: Add call to the service
}

// Cleaner queries
void DisplayManager::queryCleanerContribution()
{
    int cleanerId = Console::promptInteger("Cleaner ID");

    ApplicationServices appServices;
    appServices.getCleanerContribution(cleanerId);

    // TODO: implement the rest of the function
}

// User queries
void DisplayManager::queryIndividualPoints()
{
    // TODO: Implement when getCurrentUser is fixed
}

void DisplayManager::queryLogin()
{
    string email = Console::promptString("Email");
    string password = Console::promptString("Password");

    int res = UserServices::authenticate(email, password);

    if (res == -1) {
        Console::displayMessage("Given account does not exist, please try again");
        queryIndividualRegister();
    }
    if (res == -2) {
        Console::displayMessage("Incorrect password, please try again");
        queryIndividualRegister();
    }

}

void DisplayManager::queryLogout()
{
}

void DisplayManager::queryIndividualRegister()
{
    string email = Console::promptString("Email");
    string password = Console::promptString("Password");

    int res = UserServices::registerIndividual(email, password);

    if (res == -1) {
        Console::displayMessage("Given account already exists, please try again");
        queryIndividualRegister();
    }
}

void DisplayManager::queryCompanyRegister()
{
    string email = Console::promptString("Email");
    string password = Console::promptString("Password");

    int res = UserServices::registerIndividual(email, password);

    if (res == -1) {
        Console::displayMessage("Given account already exists, please try again");
        queryIndividualRegister();
    }
}
