#include "Utility.h"
#include "Reaper.h"
#include "Color.h"
#include <iostream>
using namespace std;

Reaper::Reaper(int HealthMax, int attack, int defense):Character(HealthMax,attack,defense)
{

}

bool Reaper::takedmg(int DMG, int Defense)
{
	if (Character::takedmg(DMG, Defense))
	{
		int theal = rand() % 40;
		if (theal == 0)
		{
			heal(2);
			MoveCursor(64, 20);
			cout << "the Reaper Healed";
		}
	}
	return true;
}

void Reaper::ColorE()
{
	cout << BRED;
}
