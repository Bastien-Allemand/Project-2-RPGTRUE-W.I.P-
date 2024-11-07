#include "Character.h"
#include "Color.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Character::Character(int GHealthMax, int GAttack, int GDefense)
{
	HealthMax = GHealthMax;
	Defense = GDefense;
	Attack = GAttack;
	Health = GHealthMax;
}
bool Character::IsDead()
{
	if (Health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Character::heal(int healing)
{
	Health += healing;
	if (Health > HealthMax)
	{
		Health = HealthMax;
	}
}

void Character::takedmg(int DMG,int Defense)
{
	int Chance = rand() % CritGet();
	int miss = rand() % 30;
	if (DMG - Defense <= 0)
	{
		Health -= 0;
	}
	else
	{
		if (Chance == 1)
		{
			Health -= DMG*2 - Defense;
			cout << "CRITICAL HIT ";
		}
		else if(miss == 0)
		{
			cout << "you Missed";
		}
		else
		{
			Health -= DMG - Defense;
		}

	}
}

void Character::levelup()
{
	HealthMax += HealthMax*0,010;

	Attack += 1;

	Defense += Defense*0,05;

	Health = HealthMax;
}

void Character::ShowStat()
{
	int x = getCursorX(), y = getCursorY();

	MoveCursor(x,y);
	cout << "Health: " << Health << " / " << HealthMax;
	int heart = ((Health * 100) / HealthMax) / 10;
	cout << "[";
	for (int i = 0; i < heart; i++)
	{
		cout << SBGREEN << " " << BDEFAULT;
	}
	for (int i = heart; i < 10; i++)
	{
		cout << BGREEN << " " << BDEFAULT;
	}
	cout << "]";
	MoveCursor(x, y+1);
	cout << "Attack: " << Attack;
	MoveCursor(x, y+2);
	cout << "Defense: " << Defense;
	MoveCursor(x, y+3);

}

void Character::ShowEstat()
{
	int x = getCursorX(), y = getCursorY();

	MoveCursor(x, y);
	cout << "Health: " << HealthGet() << " / " << MaxHealthGet();
	int heart = ((HealthGet() * 100) / MaxHealthGet()) / 10;
	cout << "[";
	for (int i = 0; i < heart; i++)
	{
		cout << SBRED << " " << BDEFAULT;
	}
	for (int i = heart; i < 10; i++)
	{
		cout << BRED << " " << BDEFAULT;
	}
	cout << "]";
	MoveCursor(x, y + 1);
	cout << "Attack: " << AttackGet();
	MoveCursor(x, y + 2);
	cout << "Defense: " << DefenseGet();
}

int Character::AttackGet()
{
	return Attack;
}

int Character::DefenseGet()
{
	return Defense;
}

int Character::CritGet()
{
	return 0;
}

int Character::HealthGet()
{
	return Health;
}

int Character::MaxHealthGet()
{
	return HealthMax;
}