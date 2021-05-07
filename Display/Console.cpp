#include <iostream>
#include <limits>
#include "Console.h"
using namespace std;

void Console::displayHeader(string message, int level) {
    const string headerBanner = "=========================";
    switch (level) {
        case 0:
            cout << endl << headerBanner << endl << " " << message << " :" << endl << headerBanner << endl << endl;
            break;
        case 1:
            cout << endl << message << endl;
            for (int i = 0; i < message.length(); i++) {
                cout << "-";
            }
            cout << endl << endl;
            break;
        default:
            cout << endl << message << endl << endl;
            break;
    }
}

int Console::promptInteger(string prompt) {
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

string Console::promptString(string prompt) {
	string valueIn = "";
	cout << prompt << " : ";
	cin >> valueIn;
	return valueIn;
}

float Console::promptFloat(string prompt) {
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

Date Console::promptDate(string prompt) {
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
