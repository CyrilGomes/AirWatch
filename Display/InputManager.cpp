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
        cout << "(!) Please enter an integer value for " << prompt << endl;
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

float InputManager::promptFloat(string prompt) {
	float valueIn = 0;
	cout << prompt << " : ";
	cin >> valueIn;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "(!) Please enter a float value for " << prompt << endl;
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
        cout << "(!) Please enter a date for " << prompt << endl;
        cout << prompt << " : ";
        cin >> valueIn;
    }
	return valueIn;
}
