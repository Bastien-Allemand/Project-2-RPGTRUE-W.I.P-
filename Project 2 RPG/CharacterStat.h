#pragma once

class CharacterStat
{
    int healthmax;
    int attackstat;
    int defenseStat;
public:
    int healthpoints;

    int x;

    int y;

    CharacterStat(int HealthMax, int attack, int defense)
    {
        healthmax = HealthMax;
        attackstat = attack;
        defenseStat = defense;
        healthpoints = HealthMax;
    }
    bool isdead();

    virtual void ShowStat();

    void heal(int healing);

    void takedmg(int DMG);

    virtual void levelup();
};
