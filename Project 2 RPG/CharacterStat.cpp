
#include "CharacterStat.h"
#include "Utility.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

bool CharacterStat::isdead()
{
    if (healthpoints > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void CharacterStat::ShowStat()
{

    cout << healthpoints << "/" << healthmax << endl << "attack :" << attackstat << endl << "Defense :" << defenseStat << endl;

}
void CharacterStat::heal(int healing)
{
    healthpoints += healing;
    if (healthpoints > healthmax)
    {
        healthpoints = healthmax;
    }
}
void CharacterStat::takedmg(int DMG)
{
    if (DMG - defenseStat >= 0)
    {
        healthpoints -= DMG;
    }
}
void CharacterStat::levelup()
{
    healthmax += (healthmax * 10) / 100;

    attackstat += (attackstat * 5) / 100;

    defenseStat += (defenseStat * 5) / 100;

    healthpoints = healthmax;
}

int CharacterStat::FightSequence()
{
    MoveCursor(0, 0);
    AllySprite();
    return 0;
}

