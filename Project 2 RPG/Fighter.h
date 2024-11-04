#pragma once
#include "Character.h"
class Fighter :public Character
{
public:

	Fighter(int GHealthMax, int GDefense, int GAttack);

	void levelup();
};

