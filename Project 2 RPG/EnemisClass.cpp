#include "EnemisClass.h"
#include "Color.h"
#include <iostream>
using namespace std;



EnemisClass::EnemisClass(int Gmana, int HealthMax, int attack, int defense) : Character(HealthMax, attack, defense)
{
	Mana = Gmana;
}

void EnemisClass::levelup()
{
	Mana += (Mana * 5) / 100;
	Character::levelup();
}

int EnemisClass::ManaGet()
{
	return Mana;
}

