#pragma once

class GameManager;
class EnemisClass;
class CharacterStat;
class tiles;

char AskChar();

int rgbToAnsi(int r, int g, int b);

int GetConsoleLength();

int GetConsoleHeight();

void FullScreen();

void MoveCursor(int x, int y);

void HideCursor();

void ClearScreen(int x, int y, int l, int h);

void ClearFullScreen();

int GetConsoleHeight();

bool GraphicKey(int* i);

int getCursorX();

int getCursorY();