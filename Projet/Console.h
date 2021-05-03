#ifndef CONSOLE_H
#define CONSOLE_H

namespace Display {
	class Console {


	public:
		void displayMessage(String message);

		float promptInteger(String prompt);

		float promptString(String prompt);

		float promptFloat(String prompt);

		void promptMenuChoice(String prompt, List<String> menuItems);
	};
}

#endif
