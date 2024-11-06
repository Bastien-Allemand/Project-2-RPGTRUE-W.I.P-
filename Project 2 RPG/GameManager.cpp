#include "GameManager.h"
#include "Tiles.h"
#include "Character.h"
#include "Assasin.h"
#include "Fighter.h"
#include "Mage.h"
#include "Color.h"
#include "Sprite.h"
#include "Visual.h"
#include "EnemisClass.h"
#include <iostream>
using namespace std;

GameManager::GameManager()
{

	for (int i = 0; i < 32; i++)
	{
		allof[i].all = new tilesId * [32];
		for (int j = 0; j < 32; j++)
		{
		allof[i].all[j] = (tilesId*)malloc(sizeof(tilesId));
		}
	}
	bool t = true;

	Mob = (EnemisClass*)malloc(sizeof(EnemisClass) * 4);

	Mob[0] = EnemisClass(1, 10, 1, 1);
	Mob[1] = EnemisClass(1, 10, 1, 2);
	Mob[2] = EnemisClass(1, 10, 1, 3);
	Mob[3] = EnemisClass(0, 10, 1, 4);
}

void GameManager::CharacterCreation(int Class)
{

	switch (Class)
	{
	case(0):
		Player = new Fighter(20, 4, 7); //PV defense Attack
		cout << "Fighter Created" << endl;
		break;
	case(1):
		Player = new Mage(10, 20, 2, 5); //MANA PV defense Attack
		cout << "Mage Created" << endl;
		break;
	case(2):
		Player = new Assasin(8, 20, 3, 3);
		cout << "Assasin created" << endl;
		break;
	default:
		break;
	}

}

void GameManager::Colorising(int y, int x)
{
	if (allof[x].all[y]->enemis == true)
	{
		cout << BRED << "  " << BDEFAULT;
	}
	else if (allof[x].all[y]->Characteer == true)
	{
		cout << SBBLUE << "  " << BDEFAULT;
	}
	else
	{
		cout << SBBROWN << "  " << BDEFAULT;
	}
}

void GameManager::FRAME()
{
	int size = 32;
	MoveCursor(0, 0);
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			Colorising(y, i);
		}
		cout << BDEFAULT << endl;
	}
}

void  GameManager::makingofmap()
{

	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			allof[x].all[y]->enemis = false;
			allof[x].all[y]->Characteer = false;

			if (x == 31 && y == 16)
			{
				allof[x].all[y]->Characteer = true;
			}
			if (x == 10 && y == 10)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &Mob[0];
			}
			if (x == 20 && y == 10)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &Mob[1];
			}
			if (x == 10 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &Mob[2];
			}
			if (x == 20 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = &Mob[3];
			}
		}
	}
}

void GameManager::Cmoved(char cMove, int* x, int* y)
{
	allof[*x].all[*y]->Characteer = false;
	switch (cMove)
	{
	case('z'):

		if (*x != 0)
		{
			*x += -1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	case('q'):
		if (*y != 0)
		{
			*y += -1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	case('s'):
		if (*x != 31)
		{
			*x += 1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	case('d'):
		if (*y != 31)
		{
			*y += 1;
		}
		allof[*x].all[*y]->Characteer = true;
		break;
	default:
		allof[*x].all[*y]->Characteer = true;
		break;
	}
}

bool GameManager::CheckEnemis(int* x, int* y,int* Ex, int* Ey)
{
	bool T = false;
	if (*x != 0)
	{
		if (allof[*x - 1].all[*y]->enemis == true)
		{
			T = true;
			*Ex = *x - 1;
			*Ey = *y;
		}
	}
	if (*x != 31)
	{
		if (allof[*x + 1].all[*y]->enemis == true)
		{
			T = true;
			*Ex = *x + 1;
			*Ey = *y;
		}
	}
	if (*y != 0)
	{
		if (allof[*x].all[*y - 1]->enemis == true)
		{
			T = true;
			*Ex = *x;
			*Ey = *y - 1;
		}
	}
	if (*y != 31)
	{
		if (allof[*x].all[*y + 1]->enemis == true)
		{
			T = true;
			*Ex = *x;
			*Ey = *y + 1;
		}
	}
	if (*x != 0 && *y != 0)
	{
		if (allof[*x - 1].all[*y - 1]->enemis == true)
		{
			T = true;
			*Ex = *x - 1;
			*Ey = *y - 1;
		}
	}
	if (*x != 0 && *y != 31)
	{
		if (allof[*x - 1].all[*y + 1]->enemis == true)
		{
			T = true;
			*Ex = *x - 1;
			*Ey = *y + 1;
		}
	}
	if (*x != 31 && *y != 31)
	{
		if (allof[*x + 1].all[*y + 1]->enemis == true)
		{
			T = true;
			*Ex = *x + 1;
			*Ey = *y + 1;
		}
	}
	if (*x != 31 && *y != 0)
	{
		if (allof[*x + 1].all[*y - 1]->enemis == true)
		{
			T = true;
			*Ex = *x + 1;
			*Ey = *y - 1;
		}
	}

	return T;
}

int GameManager::FightSequence(EnemisClass Mob)
{
	AllySprite(64, 0);
	bool endof = false;
	bool wintest = false;
	while (!endof)
	{

		MoveCursor(64, 17);
		Player->ShowStat();

		MoveCursor(94, 18);
		cout << "Attack: " << Mob.AttackGet();
		MoveCursor(94, 19);
		cout << "Defense: " << Mob.DefenseGet();


		MoveCursor(64, 11);
		int i = FightMenu();
		switch (i)
		{
		case(0):
			Mob.takedmg(Player->AttackGet(),Mob.DefenseGet());
			
			if (Mob.IsDead())
			{
				wintest = true;
				endof = true;
				break;
			}
			Player->takedmg(Mob.AttackGet(), Player->DefenseGet());
			
			if (Player->IsDead())
			{
				endof = true;
				break;
			}
			break;
		case(1):
			Mob.takedmg(Player->AttackGet(), Mob.DefenseGet());
			if (Mob.IsDead())
			{
				wintest = true;
				endof = true;
				break;
			}
			Player->takedmg(Mob.AttackGet(), Player->DefenseGet());
			if (Player->IsDead())
			{
				endof = true;
				break;
			}
			break;
		case(2):
			Mob.takedmg(Player->AttackGet(), Mob.DefenseGet());
			if (Mob.IsDead())
			{
				wintest = true;
				endof = true;
				break;
			}
			Player->takedmg(Mob.AttackGet(), Player->DefenseGet());
			if (Player->IsDead())
			{
				endof = true;
				break;
			}
			break;
		default:
			exit(1);
			break;
		}
	}
	if (wintest)
	{
		Player->levelup();
		return 0;
	}
	else
	{
		return 1;
	}

	
}