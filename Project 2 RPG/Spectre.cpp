#include "Utility.h"
#include "Spectre.h"
#include "Color.h"
#include "GameManager.h"
#include <iostream>
using namespace std;
Spectre::Spectre(int HealthMax, int attack, int defense) :Character(HealthMax, attack, defense)
{
	x = 20;
	y = 20;
}


bool Spectre::takedmg(int DMG, int Defense)
{
	if (Character::takedmg(DMG, Defense))
	{
		if (IsDead())
		{

		}
		else
		{
			GameManager::GetInstance()->SpectreMove(&x, &y);
		}
	}

	return true;
}
