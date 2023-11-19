#include "GamePlay.h"

#include <iostream>

GamePlay::GamePlay()
{

}

GamePlay::~GamePlay()
{
	delete console;
	delete menu;
	delete player;
	delete[] entities;
}

void GamePlay::RunGame()
{
	srand(time(NULL));

	console = new ConsoleHandler();
	console->SetConsoleSize(console->consoleWide, console->consoleHeight);

	menu = new Menu();

	COORD playerPos{ console->consoleWide / 2, console->consoleHeight / 2 };
	COORD playerSize{ 3, 3 };
	player = new Player(playerPos, playerSize, Color::grey);

	char input = '1';
	bool keepPlaying = true;

	while (keepPlaying)
	{
		switch (input)
		{
			case '1':
			{
				menu->ShowMenu(*console);
				break;
			}
			case '2':
			{
				GameLoop(*player, *console);
				break;
			}
		}
	}
}

void GamePlay::GameLoop(Player& player, ConsoleHandler& console)
{
	player.GetInput(console);

	Draw(player, console);
}

void GamePlay::Draw(Player& player, ConsoleHandler& console)
{
	console.DrawFrame(0);
	player.Draw(console);
}