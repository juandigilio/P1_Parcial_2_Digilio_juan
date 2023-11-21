#pragma once

#include "Entity.h"

#include <vector>

using namespace std;

class Enemy : public Entity
{
private:

	char direction;

public:

	Enemy(COORD position, COORD size, int color);
	~Enemy();

	void LoadTexture();
	void Move(ConsoleHandler* console);
	void CheckLimits(ConsoleHandler* console);
	void ResetPosition(ConsoleHandler* console);
	void ResetDirection();
	char GetDirection() { return direction; }
	void EnemyVsEnemy(vector<Entity*>& entities, Enemy* auxEnemy, ConsoleHandler* console, int entitiesQnty, int i);
};

