#pragma once
#include "CharacterStat.h"
class Fighter :public CharacterStat
{
public:
	Fighter(int HealthMax, int attack, int defense) : CharacterStat(HealthMax, attack, defense)
	{


	}
	void ShowStat() override;
	void levelup() override;
};
