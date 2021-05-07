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

int UserServices::authenticate(string uEmail, string uPassword) {
	// ApplicationData instance and user list
	ApplicationData* applicationData = ApplicationData::getInstance();
    unordered_map<string, User*> userList = applicationData->getUserList();
	// Try to find the corresponding user
    User* authenticatedUser = userList[uEmail];
	// If it doesn't exist, error code -1
    if (authenticatedUser == nullptr) {
        return -1;
    }
	// If it does exist, check passwords
    else {
		// If it's the wrong password, error code -2
        if (authenticatedUser->getPassword() != uPassword) {
            return -2;
        }
    }
	// If everything went well, set the current user
    setCurrentUser(authenticatedUser);
    return 0;
}

int UserServices::registerCompany(string uEmail, string uPassword) {
	// ApplicationData instance and user list
	ApplicationData* applicationData = ApplicationData::getInstance();
	unordered_map<string, User*> userList = applicationData->getUserList();
	// If the email already exists, error code -1
	if (userList.count(uEmail) != 0) {
	   return -1;
	}
	// If everything went well, create the new user and save it
	User* newUser = new Company(uEmail, uPassword);
	applicationData->addUser(newUser);
	// Persist it
	DBManager::updateLocalDataWithUser(newUser);
	return 0;
}

int UserServices::registerIndividual(string uEmail, string uPassword) {
	// ApplicationData instance and user list
	ApplicationData* applicationData = ApplicationData::getInstance();
    unordered_map<string, User*> userList = applicationData->getUserList();
    if (userList.count(uEmail) != 0) {
        return -1;
    }
	// If everything went well, create the new user and save it
    User* newUser = new Individual(uEmail, uPassword);
    applicationData->addUser(newUser);
	// Persist it
	DBManager::updateLocalDataWithUser(newUser);
	return 0;
}
