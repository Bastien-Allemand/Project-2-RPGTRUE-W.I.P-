#pragma once
#include "Visual.h"
#include "Utility.h"
#include "Golem.h"
#include "Spectre.h"
#include "Reaper.h"
#include "Character.h"
#include "Tiles.h"
class GameManager 
{
private:
	static GameManager* instance;
public:
	Golem* golem;
	Spectre* spectre;
	Reaper** reaper;
	Character* Player;

	tiles* allof = new tiles[32];

	static GameManager* GetInstance();

	GameManager();

	void CharacterCreation(int Class);

	void Colorising(int y, int x);

	void FRAME();

	void makingofmap();

	void Cmoved(char cMove, int* x, int* y);

	bool CheckEnemis(int* x, int* y, int* Ex, int* Ey);

	int GetPlayerx();

	int GetPlayery();

	int FightSequence(Character *Mob,int x,int y);

	void GetSpecter(int* x, int* y);

	void FightChoice(int i);

	void SpectreMove();

	bool Checkforwin();
};

	