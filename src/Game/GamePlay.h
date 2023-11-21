#pragma once

#include "Timer.h"
#include "ConsoleHandler.h"
#include "Menu.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

#include <vector>

using namespace std;

class GamePlay
{
private:

	Timer* frameTimer;
	Timer enemyTimer[7];
	ConsoleHandler* console;
	Menu* menu;
	Player* player;
	vector<Entity*> entities;

	int entitiesQnty = 10;

	bool keepPlaying;


public:

	GamePlay();
	~GamePlay();

	void RunGame();
	void GameLoop();
	void Update();
	void Draw();
	void CheckPowerUps(Entity* entity);
	void ResetPositions(Enemy* enemy, int i);
	void ManageEnemies(Enemy* auxEnemy, Timer& timer, int i);
	bool CheckPlayerVsEnemy(Enemy* auxEnemy, int i);
};

