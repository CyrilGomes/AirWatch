#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <vector>
#include <functional>
using namespace std;

class Console {
	public:
		static void displayMessage(string message);
		static int promptInteger(string prompt);
		static string promptString(string prompt);
		static float promptFloat(string prompt);
};

#endif
