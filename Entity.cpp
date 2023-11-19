#include "Entity.h"

#include <iostream>



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

void Entity::CheckLimits(ConsoleHandler& console)
{
	int topLimit = 1;
	int bottomLimit = console.consoleHeight - size.Y - 1;
	int leftLimit = 1;
	int rightLimit = console.consoleWide - size.X - 1;

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
