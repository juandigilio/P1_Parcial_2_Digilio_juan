#include "GamePlay.h"

#include <iostream>

#include "Collectables.h"
#include "ExtraLife.h"
#include "ExtraPoints.h"
#include "DoublePoints.h"


GamePlay::GamePlay()
{
	srand(time(nullptr));

	frameTimer = new Timer();
	//enemyTimer = new Timer[7];

	console = new ConsoleHandler();
	console->SetConsoleFont(20, 25);
	console->SetConsoleSize(console->consoleWide, console->consoleHeight);

	menu = new Menu();

	COORD playerPos{ console->consoleWide / 2, console->consoleHeight / 2 };
	COORD playerSize{ 3, 3 };
	player = new Player(playerPos, playerSize, Color::grey);
	player->LoadTexture();


	for (int i = 0; i < entitiesQnty; i++)
	{
		COORD auxPos{ (rand() % console->consoleWide - 4) + 2, (rand() % console->consoleHeight - 5) + 2 };
		COORD enemySize{ 3, 3 };
		COORD powerUpSize{ 2, 2 };

		if (i < 7)
		{
			entities.push_back(new Enemy(auxPos, enemySize, Color::red));
		}
		else if (i == 7)
		{
			entities.push_back(new ExtraLife(auxPos, powerUpSize, Color::green));
		}
		else if (i == 8)
		{
			entities.push_back(new ExtraPoints(auxPos, powerUpSize, Color::blue));
		}
		else if (i == 9)
		{
			entities.push_back(new DoublePoints(auxPos, powerUpSize, Color::yellow));
		}

		for (int j = 0; j < i; j++)
		{
			while (entities[j]->CheckCollision(entities[i]->GetTexture(), entities[i]->GetSize()) || 
				    player->CheckCollision(entities[i]->GetTexture(), entities[i]->GetSize()))
			{
				auxPos.X = (rand() % console->consoleWide - 4) + 2;
				auxPos.Y = (rand() % console->consoleHeight - 5) + 2;

				entities[i]->SetPosition(console, auxPos);
			}
		}
	}

	for (int i = 0; i < entitiesQnty; i++)
	{
		Enemy* auxEnemy = dynamic_cast<Enemy*>(entities[i]);
		Collectables* auxCollectable = dynamic_cast<Collectables*>(entities[i]);

		if (auxEnemy != nullptr)
		{
			auxEnemy->LoadTexture();
		}
		else
		{
			ExtraLife* auxExtraLife = dynamic_cast<ExtraLife*>(entities[i]);
			ExtraPoints* auxExtraPoints = dynamic_cast<ExtraPoints*>(entities[i]);
			DoublePoints* auxDoublePoints = dynamic_cast<DoublePoints*>(entities[i]);

			if (auxExtraLife != nullptr)
			{
				auxExtraLife->LoadTexture();
				auxExtraLife->CheckLimits(console);
			}
			else if (auxExtraPoints != nullptr)
			{
				auxExtraPoints->LoadTexture();
				auxExtraPoints->CheckLimits(console);
			}
			else if (auxDoublePoints != nullptr)
			{
				auxDoublePoints->LoadTexture();
				auxDoublePoints->CheckLimits(console);
			}

			
		}
	}
}

GamePlay::~GamePlay()
{
	delete frameTimer;
	//delete& enemyTimer;
	delete console;
	delete menu;
	delete player;
	
	for (auto& object : entities) 
	{
		delete object;
	}

	entities.clear();
}

void GamePlay::RunGame()
{
	srand(time(NULL));

	keepPlaying = true;

	console->userInput = '0';

	while (keepPlaying)
	{
		switch (console->userInput)
		{
			case '0':
			{
				menu->ShowMenu(*console);
				break;
			}
			case '1':
			{
				GameLoop();
				break;
			}
		}
	}
}

void GamePlay::GameLoop()
{
	player->GetInput(console);

	Update();

	Draw();
}

void GamePlay::Update()
{
	player->Move(console);

	for (int i = 0; i < entitiesQnty; i++)
	{
		Enemy* auxEnemy = dynamic_cast<Enemy*>(entities[i]);
		Collectables* auxCollectable = dynamic_cast<Collectables*>(entities[i]);

		if (auxEnemy != nullptr)
		{
			ManageEnemies(auxEnemy, enemyTimer[i], i);

			if (CheckPlayerVsEnemy(auxEnemy, i))
			{
				break;
			}
		}
		else if (player->CheckCollision(auxCollectable->GetTexture(), auxCollectable->GetSize()))
		{
			CheckPowerUps(entities[i]);
		}
	}
}

void GamePlay::Draw()
{
	if (frameTimer->ElapsedTime(100))
	{
		console->DrawFrame(0);
	}

	player->Draw(console);

	for (int i = 0; i < entitiesQnty; i++)
	{
		Enemy* auxEnemy = dynamic_cast<Enemy*>(entities[i]);
		Collectables* auxCollectable = dynamic_cast<Collectables*>(entities[i]);

		if (auxEnemy != nullptr)
		{
			auxEnemy->Draw(console);
		}
		else if (auxCollectable != nullptr)
		{
			if (auxCollectable->IsVisible())
			{
				auxCollectable->Draw(console);
			}
		}
	}
}

void GamePlay::CheckPowerUps(Entity* entity)
{
	ExtraLife* auxExtraLife = dynamic_cast<ExtraLife*>(entity);
	ExtraPoints* auxExtraPoints = dynamic_cast<ExtraPoints*>(entity);
	DoublePoints* auxDoublePoints = dynamic_cast<DoublePoints*>(entity);

	if (auxExtraLife != nullptr)
	{
		auxExtraLife->IsCollected(player, console);
	}
	else if (auxExtraPoints != nullptr)
	{
		auxExtraPoints->IsCollected(player, console);
	}
	else if (auxDoublePoints != nullptr)
	{
		auxDoublePoints->IsCollected(player, console);
	}
}

void GamePlay::ResetPositions(Enemy* enemy, int i)
{
	COORD center = { console->consoleWide / 2, console->consoleHeight / 2 };

	player->SetPosition(console, center);

	enemy->Clean(console);
	enemy->ResetPosition(console);

	for (int j = 0; j < entitiesQnty; j++)
	{
		if (j != i)
		{
			Enemy* aux2 = dynamic_cast<Enemy*>(entities[j]);

			if (aux2 != nullptr)
			{
				while (enemy->CheckCollision(aux2->GetTexture(), aux2->GetSize()) ||
					enemy->CheckCollision(player->GetTexture(), player->GetSize()))
				{
					aux2->ResetPosition(console);
				}
			}

		}
	}
}

void GamePlay::ManageEnemies(Enemy* auxEnemy, Timer& timer, int i)
{
	if (timer.ElapsedTime(70))
	{
		auxEnemy->Move(console);
	}

	auxEnemy->EnemyVsEnemy(entities, auxEnemy, console, entitiesQnty, i);
}

bool GamePlay::CheckPlayerVsEnemy(Enemy* auxEnemy, int i)
{
	if (player->CheckCollision(auxEnemy->GetTexture(), auxEnemy->GetSize()))
	{
		player->SubstractLives();

		if (player->GetAvailableLives() == 0)
		{
			keepPlaying = false;
		}
		else
		{
			ResetPositions(auxEnemy, i);
		}

		return true;
	}

	return false;
}

