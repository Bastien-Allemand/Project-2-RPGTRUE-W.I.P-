#pragma once
#include "Tils.h"
#include "GameManager.h"
char movement();

int rgbToAnsi(int r, int g, int b);

int GetConsoleLength();

int GetConsoleHeight();

void FullScreen();

void MoveCursor(int x, int y);

void HideCursor();

void ClearScreen(int x, int y, int l, int h);

void ClearFullScreen();

int GetConsoleHeight();

void Cmoved(tils* allof, char cMove, int* x, int* y);

void CharacterCreation(int Class);

void makingofmap(tils* allof, GameManager* GameS);
