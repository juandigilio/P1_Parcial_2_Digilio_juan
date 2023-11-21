#pragma once

#include "Entity.h"

#include "ConsoleHandler.h"

class Player : public Entity
{
private:

	int maxLives;
	int availableLives;
	int totalPoints;
	int availableSteps;
	char input;

public:

	Player(COORD position, COORD size, int color);
	~Player();

	void GetInput(ConsoleHandler* console);
	bool UpdateStatus() { return availableLives && availableSteps; };
	int GetAvailableLives() { return availableLives; }
	int GetAvailableSteps() { return availableSteps; }
	int GetTotalPoints() { return totalPoints; }
	char GetInput() { return input; }
	void SubstractLives() { availableLives--; }
	void AddPoints(int points) { totalPoints += points; }
	void AddLives(int lives);

	void LoadTexture();
	void Move(ConsoleHandler* console);
	void CheckLimits(ConsoleHandler* console);
};

