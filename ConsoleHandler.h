#pragma once

#include <Windows.h>


class ConsoleHandler
{
public:

	COORD cursorPosition;
	HANDLE hwnd;
	CONSOLE_FONT_INFOEX cfi;
	SMALL_RECT rect;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	int consoleWide;
	int consoleHeight;
	int color;

	COORD menu1;
	COORD menu2;
	COORD menu3;


	ConsoleHandler();
	~ConsoleHandler();

	void SetConsoleSize(int wide, int height);
	void SetConsoleFont(int wide, int height);
	void DrawFrame(int delay);
};

