#pragma once
#include "CharacterStat.h"
using namespace std;
class Thief : public CharacterStat
{
	int critRate;
	int mana;
public:
	Thief(int Gmana, int HealthMax, int attack, int defense) : CharacterStat(HealthMax, attack, defense)
	{
		mana = Gmana;
		critRate = 25;

	}
	void levelup() override;
	void ShowStat() override;
};

