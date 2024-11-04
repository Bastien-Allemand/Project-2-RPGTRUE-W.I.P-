#pragma once
#include <iostream>
#include "Mage.h"
#include "Character.h"

Mage::Mage(int Gmana, int GHealthMax, int GDefense, int GAttack) : Character(GHealthMax, GAttack, GDefense)
{
	Mana = Gmana;
}

int Mage::ManaGet()
{
	return Mana;
}

void Mage::levelup()
{
	Mana += (Mana * 5) / 100;
	Character::levelup();
}


