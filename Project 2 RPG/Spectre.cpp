#include "Utility.h"
#include "Spectre.h"
#include "Color.h"
#include "GameManager.h"
#include <iostream>
using namespace std;
Spectre::Spectre(int HealthMax, int attack, int defense) :Character(HealthMax, attack, defense)
{

}


bool Spectre::takedmg(int DMG, int Defense)
{
    if (Character::takedmg(DMG, Defense))
    {
        if (!IsDead())
        {
            GameManager::GetInstance()->SpectreMove();
        }
        return true;
    }
    return false;
}


void Spectre::ColorE()
{
	cout << BBLACK;
}
