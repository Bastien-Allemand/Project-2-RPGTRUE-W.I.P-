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
#include <string>;
using namespace std;

char movement()
{
	char moved = _getch();
	return moved;
}

int rgbToAnsi(int r, int g, int b)
{

	r = max(0, min(255, r));
	g = max(0, min(255, g));
	b = max(0, min(255, b));

	// Convert RGB to ANSI 256 color mode
	// pour correctement formuler penser a rajoute un nouveau define j'appele oss = #define oss "\033[38;5;" puis mettre la fonction et finir avec m tres important
	// Formula: 16 + 36 * R + 6 * G + B
	int ansiCode = 16 + (36 * (r / 51)) + (6 * (g / 51)) + (b / 51);
	return ansiCode;
}

int GetConsoleLength();
int GetConsoleHeight();

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

void Cmoved(tiles* allof, char cMove, int* x, int* y)
{
	allof[*x].all[*y]->Characteer = false;
	switch (cMove)
	{
	case('z'):

		if (*x != 0)
		{
			*x += -1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	case('q'):
		if (*y != 0)
		{
			*y += -1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	case('s'):
		if (*x != 31)
		{
			*x += 1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	case('d'):
		if (*y != 31)
		{
			*y += 1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	default:
		allof[*x].all[*y]->Characteer = true;
		break;
	}
}

void makingofmap(tiles* allof, GameManager* GameS)
{

	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			allof[x].all[y]->enemis = false;
			allof[x].all[y]->Characteer = false;

			if (x == 31 && y == 16)
			{
				allof[x].all[y]->Characteer = true;
			}
			if (x == 10 && y == 10)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &GameS->Mob[0];
			}
			if (x == 20 && y == 10)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &GameS->Mob[1];
			}
			if (x == 10 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &GameS->Mob[2];
			}
			if (x == 20 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &GameS->Mob[3];
			}
		}
	}
}

bool CheckEnemis(int *x,int *y,tiles* allof)
{	
	bool T = false;
	if (*x != 0)
	{
		if (allof[*x - 1].all[*y]->enemis == true)
		{
			T = true;
		}
	}
	else if (*x != 31)
	{
		if (allof[*x + 1].all[*y]->enemis == true)
		{
			T = true;
		}
	}
	else if (*y != 0)
	{
		if (allof[*x].all[*y - 1]->enemis == true)
		{
			T = true;
		}
	}
	else if (*y != 31)
	{
		if (allof[*x].all[*y + 1]->enemis == true)
		{
			T = true;
		}
	}
	else if (*x != 0 && *y != 0)
	{
		if (allof[*x - 1].all[*y - 1]->enemis == true)
		{
			T = true;
		}
	}
	else if (*x != 0 && *y != 31)
	{
		if (allof[*x - 1].all[*y + 1]->enemis == true)
		{
			T = true;
		}
	}
	else if (*x != 31 && *y != 31)
	{
		if (allof[*x + 1].all[*y + 1]->enemis == true)
		{
			T = true;
		}
	}
	else if (*x != 31 && *y != 0)
	{
		if (allof[*x + 1].all[*y - 1]->enemis == true)
		{
			T = true;
		}
	}
	return T;
}

//int FightSequence(EnemisClass* Enemis, Character* PLayer)
//{
//	system("cls");
//	
//	EnemisSprite();
//	AllySprite();
//	int I = Fightmenu();
//	if (I == 0)
//	{
//		Enemis->takedmg(PLayer->AttackGet());
//	}
//	return 0;
//}
