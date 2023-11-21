#pragma once

#include "Collectables.h"

#include "ConsoleHandler.h"


class ExtraLife : public Collectables
{
public:

	ExtraLife(COORD position, COORD size, int color);
	~ExtraLife();

	void LoadTexture();
	void IsCollected(Player* player, ConsoleHandler* console);
};

