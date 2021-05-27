#include <iostream>
#include <limits>
#include "InputManager.h"
using namespace std;

int InputManager::promptInteger(string prompt) {
	int valueIn = 1;
    float ref = 0;
	cout << prompt << " : ";
	cin >> ref;
    valueIn = (int)ref;
    while(cin.fail() || valueIn != ref) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "(!) Please enter an integer value for " << prompt << endl;
        cout << prompt << " : ";
        cin >> ref;
        valueIn = (int)ref;
    }
	return valueIn;
}

string InputManager::promptString(string prompt) {
	string valueIn = "";
	cout << prompt << " : ";
	cin >> valueIn;
	return valueIn;
}

string InputManager::promptEmail(string prompt) {
	string valueIn = "";
	cout << prompt << " : ";
	cin >> valueIn;
	while (valueIn.find(";") != string::npos) {
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "(!) Invalid " << prompt << ", ';' is a forbidden character" << endl;
        cout << prompt << " : ";
        cin >> valueIn;
	}
	return valueIn;
}

string InputManager::promptPassword(string prompt, bool restrictLength) {
	string valueIn = "";
	cout << prompt << " : ";
	cin >> valueIn;
	if (restrictLength) {
		while (valueIn.length() < 6 || valueIn.length() > 20) {
			cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cerr << "(!) The password must have 6 to 20 characters, please try again" << endl;
	        cout << prompt << " : ";
	        cin >> valueIn;
		}
	}
	while (valueIn.find(";") != string::npos) {
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "(!) Invalid " << prompt << ", ';' is a forbidden character" << endl;
        cout << prompt << " : ";
        cin >> valueIn;
	}
	return valueIn;
}

float InputManager::promptFloat(string prompt) {
	float valueIn = 0;
	cout << prompt << " : ";
	cin >> valueIn;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "(!) Please enter a float value for " << prompt << endl;
        cout << prompt << " : ";
        cin >> valueIn;
    }
	return valueIn;
}

Date InputManager::promptDate(string prompt) {
	Date valueIn;
	cout << prompt << " : ";
    cin >> valueIn;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "(!) Please enter a correct DD/MM/YYYY date  for " << prompt << endl;
        cout << prompt << " : ";
        cin >> valueIn;
    }
	return valueIn;
}
