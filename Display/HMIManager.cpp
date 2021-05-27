#include <iostream>
#include <chrono>
#include "HMIManager.h"
#include "InputManager.h"
#include "../Model/User.h"
#include "../Model/Individual.h"
#include "../Services/UserServices.h"
#include "../Services/ApplicationServices.h"
using namespace std;

typedef pair<string, function<void()>> Option;

void HMIManager::displayHeader(string message, int level)
{
    const string headerBanner = "=========================";
    switch (level)
    {
    case 0:
        cout << endl
             << headerBanner << endl
             << " " << message << " :" << endl
             << headerBanner << endl
             << endl;
        break;
    case 1:
        cout << endl
             << message << endl;
        for (int i = 0; i < (int)message.length(); i++)
        {
            cout << "-";
        }
        cout << endl
             << endl;
        break;
    default:
        cout << endl
             << message << endl
             << endl;
        break;
    }
}

void HMIManager::displayMenu(string menuTitle, vector<Option> optionsList)
{
    // Display Menu
    displayHeader(menuTitle, 0);
    int count = 1;
    for (Option item : optionsList)
    {
        cout << count << ". " << item.first << endl;
        count++;
    }
    // Fetch menu choice
    int menuChoice = InputManager::promptInteger(">") - 1;
    // If choice is not within menu options, retry
    while (menuChoice < 0 || menuChoice >= (int)optionsList.size())
    {
        cerr << "(!) Invalid choice, please try again" << endl;
        menuChoice = InputManager::promptInteger(">") - 1;
    }
    // Execute bound function
    optionsList[menuChoice].second();
}

void HMIManager::loginMenu()
{
    // Set menu title
    const string menuTitle = "Welcome to AirWatch";
    // Build menu options
    vector<Option> optionsList = {
        Option("Login", bind(&HMIManager::queryLogin, this)),
        Option("Register", bind(&HMIManager::queryIndividualRegister, this)),
        Option("Exit", bind(&HMIManager::queryExit, this))};
    // Display menu
    displayMenu(menuTitle, optionsList);
}

void HMIManager::mainMenu()
{
    // Set menu title
    const string menuTitle = "Main menu";
    // Build menu options
    vector<Option> optionsList = {
        Option("Sensor analytics", bind(&HMIManager::sensorMenu, this)),
        Option("Cleaner analytics", bind(&HMIManager::queryCleanerContribution, this)),
    };
    // Build user-specific menu options
    User *currentUser = UserServices::getCurrentUser();
    UserType userType = currentUser->getType();
    switch (userType)
    {
    case UserType::government:
        optionsList.push_back(Option("Register Air Cleaning Company", bind(&HMIManager::queryCompanyRegister, this)));
        break;
    case UserType::individual:
        optionsList.push_back(Option("My user points", bind(&HMIManager::queryIndividualPoints, this)));
        break;
    default:
        break;
    }
    optionsList.push_back(Option("Log out", bind(&HMIManager::queryLogout, this)));
    // Display menu
    displayMenu(menuTitle, optionsList);
}

void HMIManager::sensorMenu()
{
    // Set menu title
    const string menuTitle = "Sensor analytics menu";
    // Build menu options
    vector<Option> optionsList = {
        Option("Get the air quality of a given location", bind(&HMIManager::queryPunctualAirQuality, this)),
        Option("Get the air quality of a given area", bind(&HMIManager::queryAreaAirQuality, this)),
        Option("See sensor reliabilities", bind(&HMIManager::querySensorReliability, this)),
        Option("Find data similarities", bind(&HMIManager::querySensorSimilarity, this)),
        Option("Go back", bind(&HMIManager::mainMenu, this))};
    // Display menu
    displayMenu(menuTitle, optionsList);
}

// Sensor queries
void HMIManager::querySensorReliability()
{
    cerr << "This functionality is unavailable" << endl;
    sensorMenu();
}

void HMIManager::querySensorFlag()
{
    cerr << "This functionality is unavailable" << endl;
    sensorMenu();
}

void HMIManager::querySensorSimilarity()
{
    // Display title and prompt parameters
    displayHeader("Sensor Data Similarities", 1);
    int uSensorId = InputManager::promptInteger("Sensor ID");
    Date uTBegin = InputManager::promptDate("Start Time");
    Date uTEnd = InputManager::promptDate("End Time");
    // Check date coherence
    while (uTEnd < uTBegin)
    {
        cerr << "(!) The entered time period is invalid, please try again" << endl;
        uTBegin = InputManager::promptDate("Start Time");
        uTEnd = InputManager::promptDate("End Time");
    }

    #ifdef DEBUG
    // Getting the starting time of the functionality
    auto start = chrono::high_resolution_clock::now();
    #endif
    vector<Sensor *> similarSensors;
    try
    {
        // Call service
        similarSensors = ApplicationServices::compareSensorSimilarities(uSensorId, uTBegin, uTEnd);
    }
    catch (const char *e)
    {
        // Handle service errors
        cerr << e << endl;
        sensorMenu();
        return;
    }

    #ifdef DEBUG
    // Getting the ending time of the functionality
    auto end = chrono::high_resolution_clock::now();
    // Displaying the duration
    auto timeTaken = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time: " << timeTaken.count() << " milliseconds" << endl << endl;
    #endif

    // Display result
    cout << "List of similar sensors in the given time period: " << endl;
    for (Sensor *s : similarSensors)
    {
        cout << "Sensor " << s->getId() << " (" << s->getLatitude() << "; " << s->getLongitude() << ")" << endl;
    }
    // Go back to menu
    sensorMenu();
}

void HMIManager::queryAreaAirQuality()
{
    cout << "This functionality is unavailable" << endl;
    sensorMenu();
}

void HMIManager::queryPunctualAirQuality()
{
    // Display title and prompt parameters
    displayHeader("Punctual Air Quality", 1);
    float uLat = InputManager::promptFloat("Latitude");
    float uLon = InputManager::promptFloat("Longitude");
    Date uTBegin = InputManager::promptDate("Start Time");
    Date uTEnd = InputManager::promptDate("End Time");
    // Check date coherence
    while (uTEnd < uTBegin)
    {
        cerr << "(!) The entered time period is invalid, please try again" << endl;
        uTBegin = InputManager::promptDate("Start Time");
        uTEnd = InputManager::promptDate("End Time");
    }

    #ifdef DEBUG
    // Getting the starting time of the functionality
    auto start = chrono::high_resolution_clock::now();
    #endif
    float atmo;
    try
    {
        // Call service
        atmo = ApplicationServices::getPunctualAirQuality(uLat, uLon, uTBegin, uTEnd);
    }
    catch (const char *e)
    {
        // Handle service errors
        cerr << e << endl;
        sensorMenu();
        return;
    }

    #ifdef DEBUG
    // Getting the ending time of the functionality
    auto end = chrono::high_resolution_clock::now();
    // Displaying the duration
    auto timeTaken = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time: " << timeTaken.count() << " milliseconds" << endl << endl;
    #endif

    // Display result
    cout << endl;
    cout << "ATMO level : " << atmo << endl;
    // Go back to menu
    sensorMenu();
}

// Cleaner queries
void HMIManager::queryCleanerContribution()
{
    // Display title and prompt parameters
    displayHeader("Cleaner Contribution", 1);
    int uCleanerId = InputManager::promptInteger("Cleaner ID");

    #ifdef DEBUG
    // Getting the starting time of the functionality
    auto start = chrono::high_resolution_clock::now();
    #endif
    pair<float, float> cleanerContribution;
    try
    {
        // Call service
        cleanerContribution = ApplicationServices::getCleanerContribution(uCleanerId);
    }
    catch (const char *e)
    {
        // Handle service errors
        cerr << e << endl;
        mainMenu();
        return;
    }

    #ifdef DEBUG
    // Getting the ending time of the functionality
    auto end = chrono::high_resolution_clock::now();
    // Displaying the duration
    auto timeTaken = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time: " << timeTaken.count() << " milliseconds" << endl << endl;
    #endif

    // Display result
    cout << endl;
    cout << "Radius of effect : " << cleanerContribution.first << " m" << endl;
    cout << "ATMO level decrease : " << cleanerContribution.second << endl;
    // Go back to menu
    mainMenu();
}

// User queries
void HMIManager::queryIndividualPoints()
{
    // Display title
    displayHeader("User Points", 1);
    // Call service
    Individual *individual = (Individual *)UserServices::getCurrentUser();
    int points = individual->getPoints();
    // Display result
    cout << "You have " << points << " points" << endl;
    // Go back to menu
    mainMenu();
}

void HMIManager::queryLogin()
{
    // Display title and prompt parameters
    displayHeader("Login", 1);
    string uMail = InputManager::promptEmail("Email");
    string uPassword = InputManager::promptPassword("Password", false);
    try
    {
        // Call service
        UserServices::authenticate(uMail, uPassword);
    }
    catch (const char *e)
    {
        // Handle service errors
        cerr << e << endl;
        loginMenu();
        return;
    }

    // Go back to menu
    mainMenu();
}

void HMIManager::queryLogout()
{
    // Call service
    UserServices::setCurrentUser(nullptr);
    // Go back to menu
    loginMenu();
}

void HMIManager::queryIndividualRegister()
{
    // Display title and prompt parameters
    displayHeader("Register as a private individual", 1);
    string uMail = InputManager::promptEmail("Email");
    string uPassword = InputManager::promptPassword("Password", true);
    try
    {
        // Call service
        UserServices::registerIndividual(uMail, uPassword);
    }
    catch (const char *e)
    {
        // Handle service errors
        cerr << e << endl;
        loginMenu();
        return;
    }

    // Display result
    cout << endl;
    cout << "Account successfully registered, please log in" << endl;
    // Go back to menu
    loginMenu();
}

void HMIManager::queryCompanyRegister()
{
    // Display title and prompt parameters
    displayHeader("Register company", 1);
    string uMail = InputManager::promptEmail("Email");
    string uPassword = InputManager::promptPassword("Password", true);
    try
    {
        // Call service
        UserServices::registerCompany(uMail, uPassword);
    }
    catch (const char *e)
    {
        // Handle service errors
        cerr << e << endl;
        mainMenu();
        return;
    }

    // Display result
    cout << endl;
    cout << "Company successfully registered" << endl;
    // Go back to menu
    mainMenu();
}

void HMIManager::queryExit()
{
    cout << endl;
}
