#pragma once

#include "Collectables.h"

class DoublePoints : public Collectables
{
public:

	DoublePoints(COORD position, COORD size, int color);
	~DoublePoints();

	void LoadTexture();
	void IsCollected(Player* player, ConsoleHandler* console);
};

