#pragma once
#include "CharacterStat.h"

class Thief : public CharacterStat
{
	int critRate;
	int Mana;
public:
	Thief(int Gmana, int HealthMax, int attack, int defense) : CharacterStat(HealthMax, attack, defense)
	{
		Mana = Gmana;
		critRate = 25;

	}
	void levelup() override;
	void ShowStat() override;
};

