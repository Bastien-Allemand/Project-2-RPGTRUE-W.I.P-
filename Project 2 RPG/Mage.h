#pragma once
#include "CharacterStat.h"
using namespace std;
class Mage :public CharacterStat
{
	int Mana;
public:
	Mage(int Gmana, int HealthMax, int attack, int defense) : CharacterStat(HealthMax, attack, defense)
	{
		Mana = Gmana;

	}

	void ShowStat() override;
	void levelup() override;
};

