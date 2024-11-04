#include "GameManager.h"
#include "Tiles.h"
#include "Assasin.h"
#include "Fighter.h"
#include "Mage.h"
#include "EnemisClass.h"
#include <iostream>
using namespace std;

GameManager::GameManager()
{

	for (int i = 0; i < 32; i++)
	{
		GameManager::allof[i].all = new tilesId * [32];
		for (int j = 0; j < 32; j++)
		{
		GameManager::allof[i].all[j] = (tilesId*)malloc(sizeof(tilesId));
		}
	}
	bool t = true;
}
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
		Player = new Fighter(20, 4, 2);  //PV ATTACK DEFENSE
		cout << "Fighter Created" << endl;
		break;
	case(1):
		Player = new Mage(10, 20, 4, 0); //MANA PV ATTACK DEFENSE
		cout << "Mage Created" << endl;
		break;
	case(2):
		Player = new Assasin(8, 20, 3, 1);
		cout << "Assasin created" << endl;
		break;
	default:
		break;
	}

}
