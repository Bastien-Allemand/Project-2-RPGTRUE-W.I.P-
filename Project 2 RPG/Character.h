#pragma once
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

	void takedmg(int DMG);

	int AttackGet();

	int HealthGet();

	int MaxHealthGet();

	int DefenseGet();

	void levelup();

};
