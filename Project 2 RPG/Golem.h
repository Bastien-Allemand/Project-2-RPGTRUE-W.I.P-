#pragma once
#include "Character.h"
class Golem: public Character
{
public:
	Golem(int HealthMax, int attack, int defense);

	void levelup();

	bool takedmg(int DMG, int Defense) override;
};

