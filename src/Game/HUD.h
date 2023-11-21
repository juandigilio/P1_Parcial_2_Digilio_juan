#pragma once

#include <Windows.h>

#include "Player.h"
#include "ConsoleHandler.h"


class HUD
{
private:

	COORD stepsTextPos;
	COORD stepsDataPos;
	COORD pointsTextPos;
	COORD pointsDataPos;
	COORD livesDataPos;

public:

	HUD(ConsoleHandler* console);
	~HUD();

	void ShowHud(ConsoleHandler* console, Player* player);
	void UpdateHud(ConsoleHandler* console, Player* player);
	void UpdateLives(ConsoleHandler* console, Player* player);
};

