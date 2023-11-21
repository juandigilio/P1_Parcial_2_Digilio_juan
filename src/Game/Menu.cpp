#include "Menu.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>



using namespace std;

Menu::Menu()
{
	refreshRate = 50;
	mainMenu = false;
}

Menu::~Menu()
{

}

void Menu::ShowMenu(ConsoleHandler& consoleData)
{
	string welcome = ">>Bienvenido a Pac-Boy<<";
	string option1 = "1- Nuevo juego";
	string option2 = "2- Instrucciones";
	string option3 = "ESC para salir";
	string clean = "                               ";
	COORD thisCursor{};

	bool mainMenu = true;

	thisCursor.X = (consoleData.consoleWide / 2) - (welcome.length() / 2);
	thisCursor.Y = consoleData.consoleHeight - 1;

	SetConsoleTextAttribute(consoleData.hwnd, 10);

	while (thisCursor.Y > (consoleData.consoleHeight / 20) * 8)
	{
		SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
		cout << welcome;
		Sleep(refreshRate);
		SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
		cout << clean;
		thisCursor.Y--;
		consoleData.cursorPosition.X = 2;
		consoleData.cursorPosition.Y = consoleData.consoleHeight - 1;
		SetConsoleCursorPosition(consoleData.hwnd, consoleData.cursorPosition);
		for (int i = 0; i < consoleData.consoleWide - 6; i++)
		{
			cout << (char)205;
		}

	}
	SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
	cout << welcome;

	consoleData.menu1 = thisCursor;

	thisCursor.X = (consoleData.consoleWide / 2) - (option1.length() / 2);
	thisCursor.Y = consoleData.consoleHeight - 1;

	SetConsoleTextAttribute(consoleData.hwnd, 12);

	while (thisCursor.Y > (consoleData.consoleHeight / 20) * 14)
	{
		SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
		cout << option1;
		Sleep(refreshRate);
		SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
		cout << clean;
		thisCursor.Y--;
		consoleData.cursorPosition.X = 2;
		consoleData.cursorPosition.Y = consoleData.consoleHeight - 1;
		SetConsoleCursorPosition(consoleData.hwnd, consoleData.cursorPosition);
		for (int i = 0; i < consoleData.consoleWide - 6; i++)
		{
			cout << (char)205;
		}
	}
	SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
	cout << option1;
	consoleData.menu2 = thisCursor;

	thisCursor.X = (consoleData.consoleWide / 2) - (option2.length() / 2);
	thisCursor.Y = consoleData.consoleHeight - 1;

	SetConsoleTextAttribute(consoleData.hwnd, 14);

	while (thisCursor.Y > (consoleData.consoleHeight / 20) * 16)
	{
		SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
		cout << option2;
		Sleep(refreshRate);
		SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
		cout << clean;
		thisCursor.Y--;
		consoleData.cursorPosition.X = 2;
		consoleData.cursorPosition.Y = consoleData.consoleHeight - 1;
		SetConsoleCursorPosition(consoleData.hwnd, consoleData.cursorPosition);
		for (int i = 0; i < consoleData.consoleWide - 6; i++)
		{
			cout << (char)205;
		}
	}
	SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
	cout << option2;
	consoleData.menu3 = thisCursor;

	Sleep(refreshRate * 15);

	SetConsoleTextAttribute(consoleData.hwnd, 9);

	thisCursor.X = (consoleData.consoleWide / 2) - (option3.length() / 2);
	thisCursor.Y = (consoleData.consoleHeight / 20) * 18;
	SetConsoleCursorPosition(consoleData.hwnd, thisCursor);
	cout << option3;

	refreshRate = 0;

	CheckMenuInput(consoleData);
}

void Menu::ShowInstructions(ConsoleHandler& consoleData)
{
	string inst1 = "A W S D para moverse...";
	string clean = "                                   ";

	consoleData.cursorPosition.X = (consoleData.consoleWide / 2) - (inst1.length() / 2);
	consoleData.cursorPosition.Y = (consoleData.consoleHeight / 2) - 4;
	SetConsoleCursorPosition(consoleData.hwnd, consoleData.cursorPosition);
	SetConsoleTextAttribute(consoleData.hwnd, 14);
	cout << inst1;

	while (consoleData.userInput != 27)
	{
		if (_kbhit())
		{
			_getch();
			consoleData.cursorPosition.X = (consoleData.consoleWide / 2) - (inst1.length() / 2);
			consoleData.cursorPosition.Y = (consoleData.consoleHeight / 2) - 4;
			SetConsoleTextAttribute(consoleData.hwnd, 14);
			SetConsoleCursorPosition(consoleData.hwnd, consoleData.cursorPosition);
			cout << clean;
			ShowMenu(consoleData);
		}

		consoleData.DrawFrame(0);

		Sleep(500);
	}
}

void Menu::CheckMenuInput(ConsoleHandler& consoleData)
{
	string clean = "                               ";
	bool keep = true;
	int refreshRate = 500;

	while (keep)
	{
		consoleData.DrawFrame(0);
		Sleep(refreshRate);

		if (_kbhit())
		{
			SetConsoleTextAttribute(consoleData.hwnd, 8);

			consoleData.userInput = toupper(_getch());

			if (consoleData.userInput != '1' && consoleData.userInput != '2' && consoleData.userInput != 27)
			{

			}
			else
			{
				switch (consoleData.userInput)
				{
				case '1':
				{
					keep = false;
					system("cls");
					break;
				}
				case '2':
				{
					mainMenu = false;

					SetConsoleCursorPosition(consoleData.hwnd, consoleData.menu1);
					cout << clean;
					SetConsoleCursorPosition(consoleData.hwnd, consoleData.menu2);
					cout << clean;
					SetConsoleCursorPosition(consoleData.hwnd, consoleData.menu3);
					cout << clean;

					ShowInstructions(consoleData);
					break;
				}
				case 27:
				{
					keep = false;
					break;
				}
				}
			}
		}

	}
}
