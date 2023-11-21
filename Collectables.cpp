#include "Collectables.h"

Collectables::Collectables(COORD position, COORD size, int color) : Entity(position, size, color)
{
	isVisible = true;
}

Collectables::~Collectables()
{

}

void Collectables::Move(ConsoleHandler* console)
{
	
}

void Collectables::CheckLimits(ConsoleHandler* console)
{
	int topLimit = 2;
	int bottomLimit = console->consoleHeight - size.Y - 3;
	int leftLimit = 2;
	int rightLimit = console->consoleWide - size.X - 2;

	if (actualPos.Y > bottomLimit)
	{
		actualPos.Y = bottomLimit;
	}
	if (actualPos.Y < topLimit)
	{
		actualPos.Y = topLimit;
	}
	if (actualPos.X > rightLimit)
	{
		actualPos.X = rightLimit;
	}
	if (actualPos.X < leftLimit)
	{
		actualPos.X = leftLimit;
	}
}
