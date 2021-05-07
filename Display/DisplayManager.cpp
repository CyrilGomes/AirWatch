#include <iostream>
#include "DisplayManager.h"
#include "Console.h"
#include "../Model/User.h"
#include "../Model/Individual.h"
#include "../Services/UserServices.h"
#include "../Services/ApplicationServices.h"
using namespace std;

typedef pair<string, function<void()>> Option;

void DisplayManager::displayMenu(string menuTitle, vector<Option> optionsList) {
    // Display Menu
    Console::displayHeader(menuTitle, 0);
    int count = 1;
    for (Option item : optionsList) {
        cout << count << ". " << item.first << endl;
        count++;
    }
    // Fetch menu choice
    int menuChoice = Console::promptInteger(">") - 1;
    // If choice is not within menu options, retry
    while (menuChoice < 0 || menuChoice >= optionsList.size()) {
        cout << "(!) Invalid choice, please try again" << endl;
        menuChoice = Console::promptInteger(">") - 1;
    }
    // Execute bound function
    optionsList[menuChoice].second();
}

void DisplayManager::loginMenu() {
    // Set menu title
    const string menuTitle = "Welcome to AirWatch";
    // Build menu options
    vector<Option> optionsList = {
        Option("Login", bind(&DisplayManager::queryLogin, this)),
        Option("Register", bind(&DisplayManager::queryIndividualRegister, this))
    };
    // Display menu
    displayMenu(menuTitle, optionsList);
}

void DisplayManager::mainMenu() {
    // Set menu title
    const string menuTitle = "Main menu";
    // Build menu options
    vector<Option> optionsList = {
        Option("Sensor analytics", bind(&DisplayManager::sensorMenu, this)),
        Option("Cleaner analytics", bind(&DisplayManager::queryCleanerContribution, this)),
        Option("Log out", bind(&DisplayManager::queryLogout, this))
    };
    // Build user-specific menu options
    User* currentUser = UserServices::getCurrentUser();
    UserType userType = currentUser->getType();
    switch (userType) {
        case UserType::company:
            optionsList.insert(optionsList.end() - 1, Option("Register Air Cleaning Company", bind(&DisplayManager::queryCompanyRegister, this)));
            break;
        case UserType::individual:
            optionsList.insert(optionsList.end() - 1, Option("My user points", bind(&DisplayManager::queryIndividualPoints, this)));
            break;
    }
    // Display menu
    displayMenu(menuTitle, optionsList);
}

void DisplayManager::sensorMenu() {
    // Set menu title
    const string menuTitle = "Sensor analytics menu";
    // Build menu options
    vector<Option> optionsList = {
        Option("Get the air quality of a given location", bind(&DisplayManager::queryPunctualAirQuality, this)),
        Option("Get the air quality of a given area", bind(&DisplayManager::queryAreaAirQuality, this)),
        Option("See sensor reliabilities", bind(&DisplayManager::querySensorReliability, this)),
        Option("Find data similarities", bind(&DisplayManager::querySensorSimilarity, this)),
        Option("Go back", bind(&DisplayManager::mainMenu, this))
    };
    // Display menu
    displayMenu(menuTitle, optionsList);
}

// Sensor queries
void DisplayManager::querySensorReliability()
{
    cout << "This functionality is unavailable" << endl;
    sensorMenu();
}

void DisplayManager::querySensorFlag()
{
    cout << "This functionality is unavailable" << endl;
    sensorMenu();
}

void DisplayManager::querySensorSimilarity()
{
    // Display title and prompt parameters
    Console::displayHeader("Sensor Data Similarities", 1);
    int uSensorId = Console::promptInteger("Sensor ID");
    Date uTBegin = Console::promptDate("Start Time");
    Date uTEnd = Console::promptDate("End Time");
    // Call service
    ApplicationServices appServices;
    vector<Sensor*> similarSensors = appServices.compareSensorSimilarities(uSensorId, uTBegin, uTEnd);
    // Display result
    cout << "List of similar sensors in the given time period: " << endl;
    for (Sensor* s : similarSensors) {
        cout << "Sensor " << s->getId() << " (" << s->getLatitude() << "; " << s->getLongitude() << ")" << endl;
    }
    cout << endl;
    // Go back to menu
    sensorMenu();
}

void DisplayManager::queryAreaAirQuality()
{
    cout << "This functionality is unavailable" << endl;
    sensorMenu();
}

void DisplayManager::queryPunctualAirQuality() {
    // Display title and prompt parameters
    Console::displayHeader("Punctual Air Quality", 1);
    float uLat = Console::promptFloat("Latitude");
    float uLon = Console::promptFloat("Longitude");
    Date uTBegin = Console::promptDate("Start Time");
    Date uTEnd = Console::promptDate("End Time");
    // Call service
    ApplicationServices appServices;
    float atmo = appServices.getPunctualAirQuality(uLat, uLon, uTBegin, uTEnd);
    // Handle service errors
    // TODO
    // Display result
    cout << "ATMO level : " << atmo << endl;
    cout << endl;
    // Go back to menu
    sensorMenu();
}

// Cleaner queries
void DisplayManager::queryCleanerContribution() {
    // Display title and prompt parameters
    Console::displayHeader("Cleaner Contribution", 1);
    int uCleanerId = Console::promptInteger("Cleaner ID");
    // Call service
    ApplicationServices appServices;
    pair<float, float> cleanerContribution = appServices.getCleanerContribution(uCleanerId);
    // Handle service errors
    // TODO
    // Display result
    cout << "Radius of effect : " << cleanerContribution.first << " m" << endl;
    cout << "ATMO level decrease : " << cleanerContribution.second << endl;
    cout << endl;
    // Go back to menu
    mainMenu();
}

// User queries
void DisplayManager::queryIndividualPoints() {
    // Display title
    Console::displayHeader("User Points", 1);
    // Call service
    Individual* individual = (Individual*)UserServices::getCurrentUser();
    int points = individual->getPoints();
    // Display result
    cout << "You have " << points << " points" << endl;
    cout << endl;
    // Go back to menu
    mainMenu();
}

void DisplayManager::queryLogin() {
    // Display title and prompt parameters
    Console::displayHeader("Login", 1);
    string uMail = Console::promptString("Email");
    string uPassword = Console::promptString("Password");
    // Call service
    int res = UserServices::authenticate(uMail, uPassword);
    // Handle service errors
    if (res == -1) {
        cout << "(!) Given account does not exist, please try again" << endl;
        queryLogin();
    }
    if (res == -2) {
        cout << "(!) Incorrect password, please try again" << endl;
        queryLogin();
    }
    // Go back to menu
    mainMenu();
}

void DisplayManager::queryLogout() {
    // Call service
    UserServices::setCurrentUser(nullptr);
    // Go back to menu
    loginMenu();
}

void DisplayManager::queryIndividualRegister() {
    // Display title and prompt parameters
    Console::displayHeader("Register as a private individual", 1);
    string uMail = Console::promptString("Email");
    string uPassword = Console::promptString("Password");
    // Check password length
    if (uPassword.length() < 6 || uPassword.length() > 20) {
        cout << "(!) The password must have 6 to 20 characters, please try again" << endl;
        queryIndividualRegister();
    }
    // Call service
    int res = UserServices::registerIndividual(uMail, uPassword);
    // Handle service errors
    if (res == -1) {
        cout << "(!) Given account already exists, please try again" << endl;
        queryIndividualRegister();
    }
    // Display result
    cout << endl;
    cout << "Account successfully registered, please log in" << endl;
    // Go back to menu
    loginMenu();
}

void DisplayManager::queryCompanyRegister() {
    // Display title and prompt parameters
    Console::displayHeader("Register company", 1);
    string uMail = Console::promptString("Email");
    string uPassword = Console::promptString("Password");
    // Check password length
    if (uPassword.length() < 6 || uPassword.length() > 20) {
        cout << "(!) The password must have 6 to 20 characters, please try again" << endl;
        queryCompanyRegister();
    }
    // Call service
    int res = UserServices::registerIndividual(uMail, uPassword);
    // Handle service errors
    if (res == -1) {
        cout << "(!) Given account already exists, please try again" << endl;
        queryCompanyRegister();
    }
    // Display result
    cout << endl;
    cout << "Company successfully registered" << endl;
    // Go back to menu
    mainMenu();
}
