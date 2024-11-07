#pragma once
#include <iostream>
#include "Mage.h"
#include "Visual.h"
#include "Character.h"
using namespace std;

Mage::Mage(int Gmana, int GHealthMax, int GDefense, int GAttack) : Character(GHealthMax, GAttack, GDefense)
{
	Mana = Gmana;
}

int Mage::ManaGet()
{
	return Mana;
}

void Mage::ShowStat()
{
	Character::ShowStat();
	cout << "Mana: " << Mana;

}

int Mage::SkilMenu()
{
	return MageSkillMenu();
}

void Mage::levelup()
{
	Mana += (Mana * 5) / 100;
	Character::levelup();
}


