#pragma once
#include "EnemisClass.h"
class GameManager 
{
public:
	EnemisClass* Mob;
	CharacterStat* Player[1];
	void EnemisCreation();
	void CharacterCreation(int Class);
};

