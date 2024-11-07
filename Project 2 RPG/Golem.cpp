#include "Utility.h"
#include "Golem.h"
#include "Color.h"
#include <iostream>
using namespace std;


Golem::Golem(int HealthMax, int attack, int defense) : Character(HealthMax, attack, defense)
{

}
void Golem::levelup()
{

}

bool Golem::takedmg(int DMG, int Defense)
{
	int u = rand() % 50;
	if (u == 0)
	{
		Character::takedmg(DMG, Defense + 999);
	}
	Character::takedmg(DMG, Defense);
	return false;
}
