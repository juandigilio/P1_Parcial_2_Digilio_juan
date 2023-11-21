#include "Entity.h"

#include <iostream>



using namespace std;


Entity::Entity(COORD position, COORD size, int color)
{
	this->actualPos = position;
	lastPos = actualPos;
	this->size = size;
	
	texture = new Texture* [size.X];

	for (int i = 0; i < size.X; i++)
	{
		texture[i] = new Texture[size.Y];
	}

	COORD aux = position;

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			texture[i][j].color = color;
			texture[i][j].isPainted = false;
			texture[i][j].position.X = aux.X;
			texture[i][j].position.Y = aux.Y;
			aux.X++;
		}
		aux.X = position.X;
		aux.Y++;
	}
}

Entity::~Entity()
{
	delete[] texture;

	cout << "Entity destroyed" << endl;
}

void Entity::UpdateTexturePositions()
{
	COORD aux = actualPos;

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			texture[i][j].position.X = aux.X;
			texture[i][j].position.Y = aux.Y;
			aux.X++;
		}
		aux.X = actualPos.X;
		aux.Y++;
	}
}

void Entity::Draw(ConsoleHandler* console)
{
	Clean(console);

	COORD cursorPos = actualPos;

	SetConsoleTextAttribute(console->hwnd, texture[0][0].color);

	for (int i = 0; i < size.X; i++)
	{
		SetConsoleCursorPosition(console->hwnd, cursorPos);

		for (int j = 0; j < size.Y; j++)
		{
			cout << texture[i][j].image;
		}

		cursorPos.Y++;
	}
}

void Entity::Clean(ConsoleHandler* console)
{
	COORD cursorPos;
	cursorPos.X = lastPos.X;
	cursorPos.Y = lastPos.Y;

	SetConsoleTextAttribute(console->hwnd, texture[0][0].color);

	for (int i = 0; i < size.X; i++)
	{
		SetConsoleCursorPosition(console->hwnd, cursorPos);

		for (int j = 0; j < size.Y; j++)
		{
			cout << ' ';
		}

		cursorPos.Y++;
	}

	lastPos = actualPos;
}

void Entity::SetPosition(ConsoleHandler* console, COORD position)
{
	actualPos = position;

	Clean(console);

	UpdateTexturePositions();
}

bool Entity::CheckCollision(Texture** entity, COORD entitySize)
{
	for (int i = 0; i < this->size.X; i++)
	{
		for (int j = 0; j < this->size.Y; j++)
		{
			for (int k = 0; k < entitySize.X; k++)
			{
				for (int l = 0; l < entitySize.Y; l++)
				{
					if (this->texture[i][j].isPainted && entity[k][l].isPainted)
					{
						bool x = (this->texture[i][j].position.X == entity[k][l].position.X);
						bool y = (this->texture[i][j].position.Y == entity[k][l].position.Y);

						if (x && y)
						{
							return true;
						}
					}
					
				}
			}
		}
	}

	return false;
}
