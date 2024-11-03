#pragma once
#include "CharacterStat.h"
class EnemisClass : public CharacterStat
{
	int Mana;

public:
	EnemisClass(int Gmana, int HealthMax, int attack, int defense);

	void levelup() override;

	void ShowStat() override;
};

