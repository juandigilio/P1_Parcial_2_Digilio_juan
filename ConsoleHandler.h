#pragma once

#include <Windows.h>

struct Vector2
{
	int x;
	int y;
};

class ConsoleHandler
{
public:
	static COORD cursorPosition;
	static HANDLE hwnd;
	CONSOLE_FONT_INFOEX cfi;
	SMALL_RECT rect;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	static int consoleWide;
	static int consoleHeight;
	int color;

	ConsoleHandler();
	~ConsoleHandler();

	void SetConsoleSize(int wide, int height);
	void SetConsoleFont(int wide, int height);
};

