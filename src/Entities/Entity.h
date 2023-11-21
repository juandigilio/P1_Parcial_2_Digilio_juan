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

	COORD actualPos;
	COORD lastPos;
	COORD size;
	Texture** texture;


public:

	Entity(COORD position, COORD size, int color);
	virtual ~Entity();

	void UpdateTexturePositions();
	void Draw(ConsoleHandler* console);
	void Clean(ConsoleHandler* console);
	void SetPosition(ConsoleHandler* console, COORD position);
	bool CheckCollision(Texture** entity, COORD size);
	COORD GetPosition() {return actualPos;}
	COORD GetSize() { return size; }
	Texture** GetTexture() { return texture; }


	virtual void LoadTexture() = 0;
	virtual void Move(ConsoleHandler* console) = 0;
	virtual void CheckLimits(ConsoleHandler* console) = 0;
};

