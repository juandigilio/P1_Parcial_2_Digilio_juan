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

void Entity::CheckCollision(Entity entitie)
{

}
