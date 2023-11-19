#pragma once

#include "ConsoleHandler.h"

class Menu
{
private:

	int refreshRate;
	char input;
	bool mainMenu;

public:

	Menu();
	~Menu();

	void ShowMenu(ConsoleHandler& console);
	void ShowInstructions(ConsoleHandler& consoleData);
	void CheckMenuInput(ConsoleHandler& consoleData);
};

