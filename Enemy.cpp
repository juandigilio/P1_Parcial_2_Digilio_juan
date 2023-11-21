#include "Enemy.h"

#include <iostream>
#include <Windows.h>

#include "ConsoleHandler.h"

using namespace std;


Enemy::Enemy(COORD position, COORD size, int color) : Entity(position, size, color)
{
	int ran = rand() % 4;

	switch (ran)
	{
	case 0:
	{
		direction = 'U';
		break;
	}
	case 1:
	{
		direction = 'D';
		break;
	}
	case 2:
	{
		direction = 'L';
		break;
	}
	case 3:
	{
		direction = 'R';
		break;
	}
	}
}

Enemy::~Enemy()
{
	cout << "Enemy deleted!";
}

void Enemy::LoadTexture()
{
	char textureToLoad[3][3] = {
	{' ','O',' '},
	{'/','|',92},
	{'/',' ',92},
	};

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			texture[i][j].image = textureToLoad[i][j];

			if (texture[i][j].image != ' ')
			{
				texture[i][j].isPainted = true;
			}
		}
	}

	UpdateTexturePositions();
}

void Enemy::Move(ConsoleHandler* console)
{
	lastPos = actualPos;

	if (direction == 'U')
	{
		actualPos.Y--;

		CheckLimits(console);

		UpdateTexturePositions();
	}
	else if (direction == 'D')
	{
		actualPos.Y++;

		CheckLimits(console);

		UpdateTexturePositions();
	}
	else if (direction == 'L')
	{
		actualPos.X--;

		CheckLimits(console);

		UpdateTexturePositions();
	}
	else if (direction == 'R')
	{
		actualPos.X++;

		CheckLimits(console);

		UpdateTexturePositions();
	}
}

void Enemy::CheckLimits(ConsoleHandler* console)
{
	int topLimit = 1;
	int bottomLimit = console->consoleHeight - size.Y - 2;
	int leftLimit = 1;
	int rightLimit = console->consoleWide - size.X - 1;

	int ran = rand() % 3;

	if (actualPos.Y > bottomLimit)
	{
		actualPos.Y = bottomLimit;

		switch (ran)
		{
			case 0:
			{
				direction = 'U';
				break;
			}
			case 1:
			{
				direction = 'L';
				break;
			}
			case 2:
			{
				direction = 'R';
				break;
			}
		}
	}
	else if (actualPos.Y < topLimit)
	{
		actualPos.Y = topLimit;

		switch (ran)
		{
			case 0:
			{
				direction = 'D';
				break;
			}
			case 1:
			{
				direction = 'L';
				break;
			}
			case 2:
			{
				direction = 'R';
				break;
			}
		}
	}
	else if (actualPos.X > rightLimit)
	{
		actualPos.X = rightLimit;

		switch (ran)
		{
			case 0:
			{
				direction = 'U';
				break;
			}
			case 1:
			{
				direction = 'L';
				break;
			}
			case 2:
			{
				direction = 'D';
				break;
			}
		}
	}
	else if (actualPos.X < leftLimit)
	{
		actualPos.X = leftLimit;

		switch (ran)
		{
			case 0:
			{
				direction = 'U';
				break;
			}
			case 1:
			{
				direction = 'D';
				break;
			}
			case 2:
			{
				direction = 'R';
				break;
			}
		}
	}
}

void Enemy::ResetPosition(ConsoleHandler* console)
{
	srand(time(NULL));

	COORD newPos{ (rand() % console->consoleWide - 4) + 2, (rand() % console->consoleHeight - 4) + 2 };

	SetPosition(console, newPos);
}

void Enemy::ResetDirection()
{
	int ran = rand() % 3;

	if (direction == 'D')
	{
		switch (ran)
		{
		case 0:
		{
			direction = 'U';
			break;
		}
		case 1:
		{
			direction = 'L';
			break;
		}
		case 2:
		{
			direction = 'R';
			break;
		}
		}
	}
	else if (direction == 'U')
	{
		switch (ran)
		{
		case 0:
		{
			direction = 'D';
			break;
		}
		case 1:
		{
			direction = 'L';
			break;
		}
		case 2:
		{
			direction = 'R';
			break;
		}
		}
	}
	else if (direction == 'R')
	{
		switch (ran)
		{
		case 0:
		{
			direction = 'U';
			break;
		}
		case 1:
		{
			direction = 'L';
			break;
		}
		case 2:
		{
			direction = 'D';
			break;
		}
		}
	}
	else if (direction == 'L')
	{
		switch (ran)
		{
		case 0:
		{
			direction = 'U';
			break;
		}
		case 1:
		{
			direction = 'D';
			break;
		}
		case 2:
		{
			direction = 'R';
			break;
		}
		}
	}
}

void Enemy::EnemyVsEnemy(vector<Entity*>& entities, Enemy* auxEnemy, ConsoleHandler* console, int entitiesQnty, int i)
{
	int iterator = 0;
	
	for (Entity* entity : entities)
	{
		if (iterator != i)
		{
			Enemy* aux2 = dynamic_cast<Enemy*>(entity);

			if (aux2 != nullptr)
			{
				if (auxEnemy->CheckCollision(aux2->GetTexture(), aux2->GetSize()))
				{
					auxEnemy->Clean(console);

					do
					{
						auxEnemy->ResetDirection();

						aux2->ResetDirection();

					} while (auxEnemy->GetDirection() == aux2->GetDirection());
				}
			}
		}

		iterator++;
	}	
}
