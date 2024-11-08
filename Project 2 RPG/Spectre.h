#pragma once
#include "Character.h"
class Spectre : public Character
{
public:
	Spectre(int HealthMax, int attack, int defense);

	bool takedmg(int DMG, int Defense)override;

	void ColorE() override;
};

