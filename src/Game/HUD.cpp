#include "HUD.h"

#include <iostream>


using namespace std;


HUD::HUD(ConsoleHandler* console)
{
	string points = "Points: ";
	string steps = "Steps: ";

	stepsTextPos.X = 2;
	stepsTextPos.Y = console->consoleHeight - 1;

	stepsDataPos.X = stepsTextPos.X + steps.length();
	stepsDataPos.Y = console->consoleHeight - 1;

	pointsTextPos.X = console->consoleWide - points.length() - 5;
	pointsTextPos.Y = console->consoleHeight - 1;

	pointsDataPos.X = pointsTextPos.X + points.length();;
	pointsDataPos.Y = console->consoleHeight - 1;

	livesDataPos.X = console->consoleWide / 2 - 1;
	livesDataPos.Y = console->consoleHeight - 1;
}

HUD::~HUD()
{

}

void HUD::ShowHud(ConsoleHandler* console, Player* player)
{
	string points = "Points: ";
	string steps = "Steps: ";

	SetConsoleTextAttribute(console->hwnd, Color::grey);

	SetConsoleCursorPosition(console->hwnd, stepsTextPos);
	cout << steps << player->GetAvailableSteps();

	SetConsoleCursorPosition(console->hwnd, pointsTextPos);
	cout << points << player->GetTotalPoints();

	
	SetConsoleTextAttribute(console->hwnd, Color::red);

	SetConsoleCursorPosition(console->hwnd, livesDataPos);
	
	for (int i = 0; i < player->GetAvailableLives(); i++)
	{
		cout << (char)03;
	}

}

void HUD::UpdateHud(ConsoleHandler* console, Player* player)
{
	SetConsoleTextAttribute(console->hwnd, Color::grey);

	SetConsoleCursorPosition(console->hwnd, stepsDataPos);
	cout << "    ";

	SetConsoleCursorPosition(console->hwnd, stepsDataPos);
	cout << player->GetAvailableSteps();

	SetConsoleCursorPosition(console->hwnd, pointsDataPos);
	cout << "    ";

	SetConsoleCursorPosition(console->hwnd, pointsDataPos);
	cout << player->GetTotalPoints();
}

void HUD::UpdateLives(ConsoleHandler* console, Player* player)
{
	SetConsoleTextAttribute(console->hwnd, Color::red);

	SetConsoleCursorPosition(console->hwnd, livesDataPos);
	cout << "      ";

	SetConsoleCursorPosition(console->hwnd, livesDataPos);

	for (int i = 0; i < player->GetAvailableLives(); i++)
	{
		cout << (char)03;
	}
}
