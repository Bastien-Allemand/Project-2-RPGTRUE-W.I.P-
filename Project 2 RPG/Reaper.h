#pragma once
#include "Character.h"
class Reaper : public Character
{
public:
	Reaper(int HealthMax, int attack, int defense);

	bool takedmg(int DMG, int Defense) override;
};

