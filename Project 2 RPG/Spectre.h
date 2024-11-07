#pragma once
#include "Character.h"
class Spectre : public Character
{
public:
	int x;
	int y;
	Spectre(int HealthMax, int attack, int defense);

	bool takedmg(int DMG, int Defense) override;
};

