#include "Fighter.h"
#include "Character.h"

Fighter::Fighter(int GHealthMax, int GDefense, int GAttack) : Character(GHealthMax, GAttack, GDefense)
{

}

void Fighter::levelup()
{
	&Character::levelup;
}
