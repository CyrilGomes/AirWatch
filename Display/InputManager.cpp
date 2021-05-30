#include <iostream>
#include <limits>
#include "InputManager.h"
using namespace std;

/* -------------------------------------------------------------------------- */
/* METHOD: promptInteger() -------------------------------------------------- */
/* Prompts for an integer (prompts again if input is not an integer) -------- */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* METHOD: promptString() --------------------------------------------------- */
/* Prompts for a string ----------------------------------------------------- */
/* -------------------------------------------------------------------------- */
string InputManager::promptString(string prompt) {
	string valueIn = "";
	cout << prompt << " : ";
	cin >> valueIn;
	return valueIn;
}

/* -------------------------------------------------------------------------- */
/* METHOD: promptEmail() ---------------------------------------------------- */
/* Prompts for an email (prompts again if input contains ';') --------------- */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* METHOD: promptPassword() ------------------------------------------------- */
/* Prompts for a password (prompts again if input contains ';' / is too short)*/
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* METHOD: promptFloat() ---------------------------------------------------- */
/* Prompts for a float (prompts again if input is not a float) -------------- */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* METHOD: promptDate() ----------------------------------------------------- */
/* Prompts for a date (prompts again if input is badly formatted) ----------- */
/* -------------------------------------------------------------------------- */
Date InputManager::promptDate(string prompt) {
	Date valueIn;
	cout << prompt << " : ";
    cin >> valueIn;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "(!) Please enter a correct DD/MM/YYYY date for " << prompt << endl;
        cout << prompt << " : ";
        cin >> valueIn;
    }
	return valueIn;
}
