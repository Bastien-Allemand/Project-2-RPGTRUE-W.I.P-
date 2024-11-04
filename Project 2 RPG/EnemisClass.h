#pragma once

#include "Character.h"

class EnemisClass : public Character
{
	int Mana;

public:
	EnemisClass(int Gmana, int HealthMax, int attack, int defense);

	void levelup();

	int ManaGet();
};

