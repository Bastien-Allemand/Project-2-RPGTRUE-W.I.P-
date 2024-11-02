#include "Thief.h"
#include "Color.h"
#include <iostream>
using namespace std;

void Thief::ShowStat()
{
	CharacterStat::ShowStat();
	cout << "Mana :" << mana << endl;
	cout << "Crit Rate :" << critRate << "%" << endl;
}

void Thief::levelup()
{
	mana = (mana * 4) / 100;
	CharacterStat::levelup();
}
