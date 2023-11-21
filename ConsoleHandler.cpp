#include "ConsoleHandler.h"

#include <iostream>

using namespace std;

ConsoleHandler::ConsoleHandler()
{
	consoleWide = 50;
	consoleHeight = 30;
	color = 144;
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
}

ConsoleHandler::~ConsoleHandler()
{
	std::cout << "ConsoleData deleted..." << std::endl;
}

void ConsoleHandler::SetConsoleSize(int wide, int height)
{
	consoleWide = wide;
	consoleHeight = height;

	coord.X = consoleWide;
	coord.Y = consoleHeight;

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1;
	rect.Right = coord.X - 1;

	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hwnd, coord);
	SetConsoleWindowInfo(hwnd, TRUE, &rect);

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void ConsoleHandler::SetConsoleFont(int wide, int height)
{
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;

	cfi.dwFontSize.X = wide;
	cfi.dwFontSize.Y = height;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void ConsoleHandler::DrawFrame(int delay)
{
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	SetConsoleTextAttribute(hwnd, color);
	color += 16;

	if (color > 224)
	{
		color = 144;
	}
	cout << ' ';

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		SetConsoleTextAttribute(hwnd, color);
		color += 16;
		if (color > 224)
		{
			color = 144;
		}

		cout << ' ';

		Sleep(delay);
	}

	SetConsoleTextAttribute(hwnd, color);
	color += 16;
	if (color > 224)
	{
		color = 144;
	}

	cout << ' ';

	cursorPosition.X = consoleWide - 1;
	cursorPosition.Y = 1;

	for (int i = 0; i < (consoleHeight - 3); i++)
	{
		SetConsoleCursorPosition(hwnd, cursorPosition);

		SetConsoleTextAttribute(hwnd, color);
		color += 16;
		if (color > 224)
		{
			color = 144;
		}

		cout << ' ';
		cursorPosition.Y++;

		if (delay > 0)
		{
			Sleep(delay + 20);
		}
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	SetConsoleTextAttribute(hwnd, color);
	color += 16;
	if (color > 224)
	{
		color = 144;
	}

	cout << ' ';

	cursorPosition.X--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		SetConsoleTextAttribute(hwnd, color);
		color += 16;
		if (color > 224)
		{
			color = 144;
		}

		cout << ' ';
		cursorPosition.X--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		Sleep(delay);
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	SetConsoleTextAttribute(hwnd, color);
	color += 16;
	if (color > 224)
	{
		color = 144;
	}

	cout << ' ';

	cursorPosition.Y--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleHeight - 2); i++)
	{
		SetConsoleTextAttribute(hwnd, color);
		color += 16;
		if (color > 224)
		{
			color = 144;
		}

		cout << ' ' << endl;
		cursorPosition.Y--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		if (delay > 0)
		{
			Sleep(delay + 20);
		}
	}

	string digitalHappiness = "DigitalHappiness";

	cursorPosition.X = (consoleWide / 2) - (digitalHappiness.length() / 2);
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < digitalHappiness.length(); i++)
	{
		SetConsoleTextAttribute(hwnd, color);
		color += 16;
		if (color > 224)
		{
			color = 144;
		}

		cout << digitalHappiness[i];
		if (delay > 0)
		{
			Sleep(100);
		}
	}

	SetConsoleTextAttribute(hwnd, color);
	color += 16;
	if (color > 224)
	{
		color = 144;
	}

	cout << (char)169;
}