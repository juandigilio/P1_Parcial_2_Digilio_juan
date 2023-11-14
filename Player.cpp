#include "Player.h"

#include<iostream>
#include <conio.h>


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
	if (kbhit())
	{
		char key = _getch();

		if (key == 24)
		{
			position.Y++;
		}
		if (key == 25)
		{
			position.Y--;
		}
		if (key == 26)
		{
			position.X++;
		}
		if (key == 27)
		{
			position.X--;
		}
	}
}
