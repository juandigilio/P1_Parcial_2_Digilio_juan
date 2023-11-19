#include "Player.h"

#include<iostream>
#include <conio.h>



using namespace std;

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

void Player::GetInput(ConsoleHandler& console)
{
	if (_kbhit())
	{
		char key = _getch();

		if (key == 24)
		{
			position.Y++;

			CheckLimits(console);
		}
		if (key == 25)
		{
			position.Y--;

			CheckLimits(console);
		}
		if (key == 26)
		{
			position.X++;

			CheckLimits(console);
		}
		if (key == 27)
		{
			position.X--;

			CheckLimits(console);
		}
	}
}

void Player::Draw(ConsoleHandler& console)
{
	COORD cursorPos = position;

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			SetConsoleCursorPosition(console.hwnd, texture[i][j].position);
			cout << texture[i][j].image;
		}

		cursorPos.Y++;
	}
}