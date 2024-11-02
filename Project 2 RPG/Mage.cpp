#pragma once
#include <iostream>
#include "Color.h"
#include "Mage.h"

void Mage::levelup()
{
	Mana += (Mana * 5) / 100;
	CharacterStat::levelup();
}

void Mage::ShowStat()
{
	CharacterStat::ShowStat();

	cout << "Mana :" << BLUE << Mana << endl;
}