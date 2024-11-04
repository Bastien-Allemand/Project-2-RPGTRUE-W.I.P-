#include "GameManager.h"
#include <iostream>
#include "CharacterStat.h"
#include "Thief.h"
#include "Fighter.h"
#include "Mage.h"
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

void GameManager::CharacterCreation(int Class)
{

	switch (Class)
	{
	case(0):
		Player[0] = new Fighter(20, 4, 2);  //PV ATTACK DEFENSE
		cout << "Fighter Created" << endl;
		break;
	case(1):
		Player[0] = new Mage(10, 20, 4, 0); //MANA PV ATTACK DEFENSE
		cout << "Mage Created" << endl;
		break;
	case(2):
		Player[0] = new Thief(8, 20, 3, 1);
		cout << "Assasin created" << endl;
		break;
	default:
		break;
	}

}