#pragma once

#include "ConsoleHandler.h"
#include "Menu.h"
#include "Entity.h"
#include "Player.h"

enum Color
{
	grey = 8,
	blue = 9,
	green = 10,
	red = 12,
	violet = 13,
	yellow = 14,
	white = 15,
};

class GamePlay
{
private:

	

	ConsoleHandler* console;
	Menu* menu;
	Player* player;
	Entity* entities;

public:

	

	GamePlay();
	~GamePlay();

	void RunGame();
	void GameLoop(Player& player, ConsoleHandler& console);
	void Draw(Player& player, ConsoleHandler& console);
};

