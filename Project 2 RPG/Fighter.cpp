#include "Fighter.h"
#include "Visual.h"
#include "Character.h"

Fighter::Fighter(int GHealthMax, int GDefense, int GAttack) : Character(GHealthMax, GAttack, GDefense)
{

}

void Fighter::levelup()
{
	&Character::levelup;
}

int Fighter::SkilMenu()
{
	return SkillMenu();
}
