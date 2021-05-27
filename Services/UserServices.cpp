#include "UserServices.h"
#include <unordered_map>
#include "../Database/DBManager.h"
#include "../Model/ApplicationData.h"
#include "../Model/User.h"
#include "../Model/Company.h"
#include "../Model/Individual.h"

User* UserServices::currentUser;

User* UserServices::getCurrentUser() {
	return currentUser;
}

void UserServices::setCurrentUser(User* user) {
	currentUser = user;
}

void UserServices::authenticate(string uEmail, string uPassword) {
	// ApplicationData instance and user list
	ApplicationData* applicationData = ApplicationData::getInstance();
    unordered_map<string, User*> userList = applicationData->getUserList();
	// Try to find the corresponding user
    User* authenticatedUser = userList[uEmail];
	// If it doesn't exist, error code -1
    if (authenticatedUser == nullptr) {
        throw "(!) Given account does not exist, please try again";
    }
	// If it does exist, check passwords
    else {
		// If it's the wrong password, error code -2
        if (authenticatedUser->getPassword() != uPassword) {
            throw "(!) Incorrect password, please try again";
        }
    }
	// If everything went well, set the current user
    setCurrentUser(authenticatedUser);

}

void UserServices::registerCompany(string uEmail, string uPassword) {
	// ApplicationData instance and user list
	ApplicationData* applicationData = ApplicationData::getInstance();
	unordered_map<string, User*> userList = applicationData->getUserList();
	// If the email already exists, error code -1
	if (userList.count(uEmail) != 0) {
	   throw "(!) Given account already exists, please try again";
	}
	// If everything went well, create the new user and save it
	User* newUser = new Company(uEmail, uPassword);
	applicationData->addUser(newUser);
	// Persist it
	DBManager::updateLocalDataWithUser(newUser);

}

void UserServices::registerIndividual(string uEmail, string uPassword) {
	// ApplicationData instance and user list
	ApplicationData* applicationData = ApplicationData::getInstance();
    unordered_map<string, User*> userList = applicationData->getUserList();
    if (userList.count(uEmail) != 0) {
        throw "(!) Given account already exists, please try again";
    }
	// If everything went well, create the new user and save it
    User* newUser = new Individual(uEmail, uPassword);
    applicationData->addUser(newUser);
	// Persist it
	DBManager::updateLocalDataWithUser(newUser);

}
