#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <list>
using namespace std;

class Console {

	public:
		static void displayMessage(string message);
		static int promptInteger(string prompt);
		static string promptString(string prompt);
		static float promptFloat(string prompt);
		static int promptMenuChoice(string prompt, list<string> menuItems);

};

#endif
