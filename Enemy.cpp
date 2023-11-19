#include "Enemy.h"

#include <iostream>
#include <Windows.h>

#include "ConsoleHandler.h"

using namespace std;


Enemy::Enemy(COORD position, COORD size, int color) : Entity(position, size, color)
{

}

Enemy::~Enemy()
{
	cout << "Enemy deleted!";
}

void Enemy::Draw(ConsoleHandler& console)
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

void Enemy::Move()
{
}
