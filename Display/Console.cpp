#include <iostream>
#include <limits>
#include "Console.h"
using namespace std;

void Console::displayMessage(string message) {
    cout << message << endl;
}

int Console::promptInteger(string prompt) {
	int valueIn = 1;
    float ref = 0;
	cout << prompt << " : ";
	cin >> ref;
    valueIn = (int)ref;
    // TODO - vérifier que l'entrée est un int;
    while(cin.fail() || valueIn!=ref)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Please enter an integer value for "<< prompt <<endl;
        cout << prompt << " : ";
        cin>>ref;
        valueIn = (int)ref;
    }
    cout << endl;
	return valueIn;

}

string Console::promptString(string prompt) {
	string valueIn = "";
	cout << prompt << " : ";
	cin >> valueIn;
	return valueIn;
	// TODO - implement Console::promptString
}

float Console::promptFloat(string prompt) {
	float valueIn = 0;
	cout << prompt << " : ";
	cin >> valueIn;
    // TODO - vérifier que l'entrée est bien un float
    while(cin.fail() )
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Please enter a float value for "<< prompt <<endl;
        cout << prompt << " : ";
        cin>>valueIn;
    }
    cout << endl;
	return valueIn;
}

int Console::promptMenuChoice(string prompt, list<string> menuItems) {

    cout << prompt << " :" << endl;
    int count = 1;
    for (string item : menuItems)
    {
        cout << count << ". "<< item << endl;
        count++;
    }
    return promptInteger(">");

}
