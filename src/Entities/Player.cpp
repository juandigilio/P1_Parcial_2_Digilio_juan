#include "Player.h"

#include<iostream>
#include <conio.h>



using namespace std;

Player::Player(COORD position, COORD size, int color) : Entity (position, size, color)
{
	maxLives = 6;
	availableLives = 3;
	totalPoints = 0;
	availableSteps = 300;
}

Player::~Player()
{
	std::cout << "Ta lueguito" << std::endl;
}

void Player::GetInput(ConsoleHandler* console)
{
	if (_kbhit())
	{
		input = toupper(_getch());
	}
}

void Player::AddLives(int lives)
{
	availableLives += lives;

	if (availableLives > 6)
	{
		availableLives = 6;
	}
}

void Player::LoadTexture()
{
	char textureToLoad[3][3] = {
	{' ','O',' '},
	{'/','|',92},
	{'/',' ',92},
	};

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			texture[i][j].image = textureToLoad[i][j];

			if (texture[i][j].image != ' ')
			{
				texture[i][j].isPainted = true;
			}
		}
	}

	UpdateTexturePositions();
}

void Player::Move(ConsoleHandler* console)
{
	lastPos = actualPos;

	if (input == 'S')
	{
		actualPos.Y++;

		CheckLimits(console);

		UpdateTexturePositions();
	}
	else if (input == 'W')
	{
		actualPos.Y--;

		CheckLimits(console);

		UpdateTexturePositions();
	}
	else if (input == 'D')
	{
		actualPos.X++;

		CheckLimits(console);

		UpdateTexturePositions();
	}
	else if (input == 'A')
	{
		actualPos.X--;

		CheckLimits(console);

		UpdateTexturePositions();
	}

	input = ' ';
}

void Player::CheckLimits(ConsoleHandler* console)
{
	int topLimit = 1;
	int bottomLimit = console->consoleHeight - size.Y - 2;
	int leftLimit = 1;
	int rightLimit = console->consoleWide - size.X - 1;

	if (actualPos.Y > bottomLimit)
	{
		actualPos.Y = bottomLimit;
	}
	else if (actualPos.Y < topLimit)
	{
		actualPos.Y = topLimit;
	}
	else if (actualPos.X > rightLimit)
	{
		actualPos.X = rightLimit;
	}
	else if (actualPos.X < leftLimit)
	{
		actualPos.X = leftLimit;
	}
	else
	{
		availableSteps--;
	}
}

