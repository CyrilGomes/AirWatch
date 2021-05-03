#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include <list>
using namespace std;
class Console {


	public:
		void displayMessage(string message);

		int promptInteger(string prompt);

		string promptString(string prompt);

		float promptFloat(string prompt);

		int promptMenuChoice(string prompt, list<string> menuItems);
};

#endif
