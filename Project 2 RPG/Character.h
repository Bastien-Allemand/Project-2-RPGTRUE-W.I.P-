#pragma once
#include "Character.h"
class Character
{
	
public:

	int HealthMax;
	int Health;
	int Defense;
	int Attack;


	int x;
	int y;

	Character(int GHealthMax, int GDefense, int GAttack);

	bool IsDead();

	void heal(int healing);

	virtual bool takedmg(int DMG,int Defense);

	int DmgGet();

	int AttackGet();

	int HealthGet();

	int MaxHealthGet();

	int DefenseGet();

	virtual int CritGet();

	void levelup();

	void ShowStat();

	void ShowEstat();

	virtual int SkilMenu();

	virtual void ColorE();

};

