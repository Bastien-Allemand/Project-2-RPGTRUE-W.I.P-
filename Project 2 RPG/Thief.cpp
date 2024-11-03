#include "Thief.h"
#include "Color.h"
#include <iostream>
using namespace std;

void Thief::ShowStat()
{
	CharacterStat::ShowStat();
	cout << "Mana :" << Mana << endl;
	cout << "Crit Rate :" << critRate << "%" << endl;
}

void Thief::levelup()
{
	Mana = (Mana * 4) / 100;
	CharacterStat::levelup();
}
