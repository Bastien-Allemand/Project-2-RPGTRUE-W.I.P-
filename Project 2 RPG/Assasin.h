#pragma once
#include "Character.h"
class Assasin : public Character
{
	int critRate;
	int Mana;
public:
	Assasin(int GMana, int GHealthMax, int GDefense, int GAttack);
	int CritGet();
	void ShowStat();
	int ManaGet();
	void levelup();

};

	