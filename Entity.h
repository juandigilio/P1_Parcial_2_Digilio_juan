#pragma once

#include <Windows.h>

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
	void Draw();
	bool CheckCollision(Entity entity);
	COORD GetPosition() {return position;}
	COORD GetSize() { return size; }
};

