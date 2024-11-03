#include "EnemisClass.h"
#include "Color.h"
#include <iostream>
using namespace std;



EnemisClass::EnemisClass(int Gmana, int HealthMax, int attack, int defense) : CharacterStat(HealthMax, attack, defense)
{
	Mana = Gmana;
}

void EnemisClass::levelup()
{
	Mana += (Mana * 5) / 100;
	CharacterStat::levelup();
}

void EnemisClass::ShowStat()
{
	CharacterStat::ShowStat();
	cout << "Mana :" << Mana << endl;
}

