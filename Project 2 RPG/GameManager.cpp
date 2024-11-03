#include "GameManager.h"
#include <iostream>
#include "CharacterStat.h"
#include "EnemisClass.h"
using namespace std;

void GameManager::EnemisCreation()
{
	Mob = (EnemisClass*)malloc(sizeof(EnemisClass) * 4);

	Mob[0] = EnemisClass(0, 10, 2, 0);
	Mob[1] = EnemisClass(0, 10, 2, 0);
	Mob[2] = EnemisClass(0, 10, 2, 0);
	Mob[3] = EnemisClass(0, 10, 2, 0);
}
