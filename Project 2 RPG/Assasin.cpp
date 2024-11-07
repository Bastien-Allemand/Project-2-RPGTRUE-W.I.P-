#pragma once
#include "Assasin.h"
#include "Character.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Assasin::Assasin(int GMana, int GHealthMax, int GDefense, int GAttack) : Character(GHealthMax, GDefense, GAttack)
{
	Mana = GMana;
	critRate = 25;
}

void Assasin::levelup()
{
	&Character::levelup;
	Mana += (Mana * 5) / 100;
}

int Assasin::CritGet()
{
	return critRate;
}

void Assasin::ShowStat()
{
	Character::ShowStat();
	cout << "Mana: " << Mana;
	int x = getCursorX(), y = getCursorY();
	MoveCursor(x, y+1);
	cout << "Crit Rate: " << critRate;
}

int Assasin::ManaGet()
{
	return Mana;
}

int Assasin::DmgGet()
{
	if (rand()%critRate == 0)
	{
		return AttackGet() * 2;
	}
	else
	{
		return AttackGet();
	}
}
