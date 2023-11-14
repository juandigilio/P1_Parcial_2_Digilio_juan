#pragma once

#include "Entity.h"


class Player : public Entity
{
private:

	int maxLives;
	int availableLives;
	int totalPoints;
	int availableSteps;

public:

	Player(COORD position, COORD size, int color);
	~Player();

	void GetInput();

	bool UpdateStatus() { return availableLives && availableSteps; };
	int GetAvailableLives() { return availableLives; }
	int GetAvailableSteps() { return availableSteps; }
	int GetTotalPoints() { return totalPoints; }
};

