#pragma once
#include "Character.h"
class Mage : public Character
{
	int Mana;
public:
	Mage(int Gmana, int GHealthMax, int GDefense, int GAttack);

	int ManaGet();
	void ShowStat() override;
	void levelup();
};

