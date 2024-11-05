#pragma once
#include "EnemisClass.h"
#include "Visual.h"
#include "Utility.h"
#include "Character.h"
#include "Tiles.h"
class GameManager 
{
private:

public:
	EnemisClass* Mob;
	Character* Player;
	tiles* allof = new tiles[32];

	GameManager();

	void CharacterCreation(int Class);

	void Colorising(int y, int x);

	void FRAME();

	void makingofmap();

	void PlayerStatwindow();

	void Cmoved(char cMove, int* x, int* y);

	bool CheckEnemis(int* x, int* y, int* Ex, int* Ey);

	int FightSequence();
};

