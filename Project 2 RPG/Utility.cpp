#include "Utility.h"
#include "Sprite.h"
#include "Color.h"
#include "GameManager.h"
#include "Fighter.h"
#include "Visual.h"
#include "Mage.h"
#include "Tiles.h"
#include <iostream>
#include <windows.h>;
#include <conio.h>;

using namespace std;

char AskChar()
{
	char moved = _getch();
	return moved;
}

bool GraphicKey(int* i)
{
	int move = AskChar();
	switch (move)
	{
	case(' '):
	{
		return true;
	}
	case('q'):
		*i -= 1;
		if (*i < 0)
			*i = 2;
		return false;
	case('d'):
		*i += 1;
		*i = *i % 3;
		return false;
	default:
		break;
	}
}

int rgbToAnsi(int r, int g, int b)
{

	r = max(0, min(255, r));
	g = max(0, min(255, g));
	b = max(0, min(255, b));

	// Convert RGB to ANSI 256 color mode
	// pour correctement formuler penser a rajoute un nouveau define j'appele oss = #define oss "\033[38;5;" 
	// puis mettre la fonction et finir avec m tres important
	// Formula: 16 + 36 * R + 6 * G + B
	int ansiCode = 16 + (36 * (r / 51)) + (6 * (g / 51)) + (b / 51);
	return ansiCode;
}

void FullScreen()
{
	HWND Hwnd = GetForegroundWindow();

	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);

	SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(Hwnd, HWND_TOP, 0, 0, x, y, 0);
}

void MoveCursor(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(hConsole, coord);
}

void HideCursor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void ClearScreen(int x, int y, int l, int h)
{
	std::cout << "\033[40m";
	std::string clear(l, ' ');

	for (int i = 0; i < h; i++)
	{
		MoveCursor(x, y + i);
		std::cout << clear;
	}
}

void ClearFullScreen()
{
	std::cout << "\033[40m";
	std::string clear(GetConsoleLength(), ' ');

	for (int i = 0; i < GetConsoleHeight(); i++)
	{
		MoveCursor(0, i);
		std::cout << clear;
	}
}

int GetConsoleHeight()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	return csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Hauteur
}

int GetConsoleLength()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	return csbi.srWindow.Right - csbi.srWindow.Left + 1; // Largeur
}

int getCursorX()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	return csbi.dwCursorPosition.X;
}

int getCursorY()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	return csbi.dwCursorPosition.Y;
}