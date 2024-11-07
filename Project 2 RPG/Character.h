#pragma once
#include "Character.h"
class Character
{
	int HealthMax;
	int Health;
	int Defense;
	int Attack;

public:

	int x;
	int y;

	Character(int GHealthMax, int GDefense, int GAttack);

	bool IsDead();

	void heal(int healing);

	void takedmg(int DMG,int Defense);

	int AttackGet();

	int HealthGet();

	int MaxHealthGet();

	int DefenseGet();

	virtual int CritGet();

	void levelup();

	virtual void ShowStat();

	void ShowEstat();

};

