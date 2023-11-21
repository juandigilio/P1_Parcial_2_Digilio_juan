#pragma once

#include "Entity.h"

#include "Player.h"

class Collectables : public Entity
{
protected:

	bool isVisible;


public:

	Collectables(COORD position, COORD size, int color);
	~Collectables();

	bool IsVisible() { return isVisible; }

	void Move(ConsoleHandler* console);
	void CheckLimits(ConsoleHandler* console);

	virtual void IsCollected(Player* player, ConsoleHandler* console) = 0;
};

