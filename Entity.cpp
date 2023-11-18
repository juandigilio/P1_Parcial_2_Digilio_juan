#include "Entity.h"

#include <iostream>

#include "ConsoleHandler.h"

using namespace std;

Entity::Entity(COORD position, COORD size, int color)
{
	this->position = position;
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
	COORD aux = position;

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			texture[i][j].position.X = aux.X;
			texture[i][j].position.Y = aux.Y;
			aux.X++;
		}
		aux.X = position.X;
		aux.Y++;
	}
}

void Entity::Draw()
{
	COORD cursorPos = position;

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			SetConsoleCursorPosition(ConsoleHandler::hwnd, texture[i][j].position);
			cout << texture[i][j].image;
		}

		cursorPos.Y++;
	}
}

void Entity::CheckLimits()
{
	int topLimit = 1;
	int bottomLimit = ConsoleHandler::consoleHeight - 1;
	int leftLimit = 1;
	int rightLimit = ConsoleHandler::consoleWide - 1;

	if (position.Y > bottomLimit)
	{
		position.Y = bottomLimit;
	}
	if (position.Y < topLimit)
	{
		position.Y = topLimit;
	}
	if (position.X > rightLimit)
	{
		position.X = rightLimit;
	}
	if (position.X < leftLimit)
	{
		position.X = leftLimit;
	}
}

bool Entity::CheckCollision(Entity entity)
{
	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			for (int k = 0; k < entity.size.X; k++)
			{
				for (int l = 0; l < entity.size.Y; l++)
				{
					if (texture[i][j].isPainted && entity.texture[k][l].isPainted)
					{
						bool x = (texture[i][j].position.X == entity.texture[k][l].position.X);
						bool y = (texture[i][j].position.Y == entity.texture[k][l].position.Y);

						if (x && y)
						{
							return true;
						}
					}
					
				}
			}
		}
	}
}
