#include "DisplayManager.h"
#include "Console.h"
#include "../Model/User.h"

#include <list>
#include <string>
#include <functional>
using namespace std;

// Menu displays
void DisplayManager::displayLoginMenu()
{
}

void DisplayManager::displayMainMenu()
{
    User currentUser;
    // TODO: Add call to UserManagement::getCurrentUser() when fixed

    list<pair<string, function<void()>>> optionsList;
    optionsList.insert(optionsList.end(), pair<string, function<void()>>("Sensor analytics", function(displaySensorMenu)));
    optionsList.insert(optionsList.end(), pair<string, function<void()>>("Cleaner analytics", function(queryCleanerContribution)));

    switch (currentUser.getType())
    {
    case UserType::company:
        optionsList.insert(optionsList.end(), pair<string, function<void()>>("Register Air Cleaning Company", function(queryCompanyRegister)));
        break;

    case UserType::individual:
        optionsList.insert(optionsList.end(), pair<string, function<void()>>("My user points", function(queryIndividualPoints)));
        break;
    }

    optionsList.insert(optionsList.end(), pair<string, function<void()>>("Log out", function(queryLogout)));
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
