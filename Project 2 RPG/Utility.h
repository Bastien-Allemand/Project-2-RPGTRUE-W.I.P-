#pragma once

class GameManager;
class EnemisClass;
class CharacterStat;
class tiles;

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

void Cmoved(tiles* allof, char cMove, int* x, int* y);

void makingofmap(tiles* allof, GameManager* GameS);

int FightSequence(EnemisClass* Enemis, CharacterStat* PLayer);