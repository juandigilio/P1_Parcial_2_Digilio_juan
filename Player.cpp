#include "Player.h"

#include<iostream>
#include <conio.h>

#include "ConsoleHandler.h"


Player::Player(COORD position, COORD size, int color) : Entity (position, size, color)
{
	maxLives = 6;
	availableLives = 3;
	totalPoints = 0;
	availableSteps = 100;
}

Player::~Player()
{
	std::cout << "Ta lueguito" << std::endl;
}

void Player::GetInput()
{
	int topLimit = 1;
	int bottomLimit = ConsoleHandler::consoleHeight - 1;
	int leftLimit = 1;
	int rightLimit = ConsoleHandler::consoleWide - 1;

	if (kbhit())
	{
		char key = _getch();

		if (key == 24)
		{
			position.Y++;

			CheckLimits();
		}
		if (key == 25)
		{
			position.Y--;

			CheckLimits();
		}
		if (key == 26)
		{
			position.X++;

			CheckLimits();
		}
		if (key == 27)
		{
			position.X--;

			CheckLimits();
		}
	}
}
