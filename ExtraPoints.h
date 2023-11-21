#pragma once

#include "Collectables.h"

#include "ConsoleHandler.h"



class ExtraPoints : public Collectables
{
public:

	ExtraPoints(COORD position, COORD size, int color);
	~ExtraPoints();

	void LoadTexture();
	void IsCollected(Player* player, ConsoleHandler* console);
};

