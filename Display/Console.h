#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <vector>
#include <functional>
#include "../Model/Date.h"
using namespace std;

class Console {

	public:
		static void displayHeader(string message, int level);
		static int promptInteger(string prompt);
		static string promptString(string prompt);
		static float promptFloat(string prompt);
		static Date promptDate(string prompt);

};

#endif
