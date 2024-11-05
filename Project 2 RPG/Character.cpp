#include "Character.h"
#include "ShowStat.h"
#include <iostream>

Character::Character(int GHealthMax, int GDefense, int GAttack)
{
	HealthMax = GHealthMax;
	Defense = GDefense;
	Attack = GAttack;
	Health = GHealthMax;
	StatOf = (ShowStat*)malloc(sizeof(ShowStat) * 6);

	add(0,"Health Max: ", HealthMax);
	add(0, "Health: ", Health);
}

void Character::add(int i,const char* StatName, int Statnbr)
{
	StatOf[0].StatName = StatName;
}

bool Character::IsDead()
{
	if (Health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Character::heal(int healing)
{
	Health += healing;
	if (Health > HealthMax)
	{
		Health = HealthMax;
	}
}

void Character::takedmg(int DMG)
{
	if (DMG - Defense <= 0)
	{
		Health -= 0;
	}
	else
	{
		Health -= DMG - Defense;
	}
}

void Character::levelup()
{
	HealthMax += (HealthMax * 10) / 100;

	Attack += (Attack * 5) / 100;

	Defense += (Defense * 5) / 100;

	Health = HealthMax;
}

int Character::AttackGet()
{
	return Attack;
}

int Character::DefenseGet()
{
	return Defense;
}

int Character::HealthGet()
{
	return Health;
}

int Character::MaxHealthGet()
{
	return HealthMax;
}