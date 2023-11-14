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
private:

	COORD position;
	COORD size;
	Texture** texture;


public:

	Entity(COORD position, COORD size, int color);
	virtual ~Entity();

	void Draw();
	bool CheckCollision(Entity entity);
	COORD GetPosition() {return position;}
	COORD GetSize() { return size; }
};

