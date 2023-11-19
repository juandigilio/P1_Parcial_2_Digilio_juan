#pragma once

#include <Windows.h>

#include "ConsoleHandler.h"

struct Texture
{
	char image;
	COORD position;
	int color;
	bool isPainted;
};

class Entity
{
protected:

	COORD position;
	COORD size;
	Texture** texture;


public:

	Entity(COORD position, COORD size, int color);
	virtual ~Entity();

	void UpdateTexturePositions();
	void CheckLimits(ConsoleHandler& console);
	bool CheckCollision(Texture** entity, COORD size);
	COORD GetPosition() {return position;}
	COORD GetSize() { return size; }

	virtual void Draw(ConsoleHandler& console) = 0;
};

