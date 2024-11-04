#pragma once
#include "EnemisClass.h"
#include "Character.h"
#include "Tiles.h"
class GameManager 
{
public:
	EnemisClass* Mob;
	Character* Player;
	tiles* allof = new tiles[32];

	GameManager();

	void EnemisCreation();

	void CharacterCreation(int Class);
};

