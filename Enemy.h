#pragma once

#include "Entity.h"

class Enemy : public Entity
{
public:

	Enemy(COORD position, COORD size, int color);
	~Enemy();

	void Draw(ConsoleHandler& console);
	void Move();
};

