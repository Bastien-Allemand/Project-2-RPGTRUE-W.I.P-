#include "Assasin.h"
#include "Character.h"

Assasin::Assasin(int GMana, int GHealthMax, int GDefense, int GAttack) : Character(GHealthMax, GDefense, GAttack)
{
	Mana = GMana;
	critRate = 25;
}

void Assasin::levelup()
{
	&Character::levelup;
	Mana += (Mana * 5) / 100;
}

int Assasin::CritGet()
{
	return critRate;
}

int Assasin::ManaGet()
{
	return Mana;
}