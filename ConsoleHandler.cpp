#include "ConsoleHandler.h"

#include <iostream>

ConsoleHandler::ConsoleHandler()
{
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
