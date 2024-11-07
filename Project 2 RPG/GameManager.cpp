#include "GameManager.h"
#include "Tiles.h"
#include "Character.h"
#include "Assasin.h"
#include "Fighter.h"
#include "Golem.h"
#include "Spectre.h"
#include "Reaper.h"
#include "Mage.h"
#include "Color.h"
#include "Sprite.h"
#include "Visual.h"
#include <iostream>
using namespace std;

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}
	return instance;
}

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
	Mob = (Character**)malloc(sizeof(Character) * 4);
	Mob[0] = new Golem(10, 2, 2);
	Mob[1] = new Reaper(10, 2, 2);
	Mob[2] = new Reaper(10, 2, 2);
	Mob[3] = new Spectre(10, 2, 2);
	
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
				allof[x].all[y]->Mob = Mob[0];
			}
			if (x == 20 && y == 10)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = Mob[1];
			}
			if (x == 10 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = Mob[2];
			}
			if (x == 20 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = Mob[3];
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
		Moveto(x, y, *x - 1, *y, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	case('q'):
		Moveto(x, y, *x, *y-1, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	case('s'):
		Moveto(x, y, *x + 1, *y, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	case('d'):
		Moveto(x, y, *x, *y+1, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	default:
		allof[*x].all[*y]->Characteer = true;
		break;
	}
}

bool GameManager::CheckEnemis(int* x, int* y,int* Ex, int* Ey)
{
	for (int X = *x-1; X < *x+2; X++)
	{
		for (int Y = *y-1; Y < *y+2; Y++)
		{
			if (Moveto(&X, &Y, X, Y, false))
			{
				if (allof[X].all[Y]->enemis == true)
				{
					*Ex = X;
					*Ey = Y;
					return true;
				}
			}
		}
	}
	return false;
}

int GameManager::GetPlayerx()
{
	int size = 32;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			if (allof[i].all[y]->Characteer == true)
			{
				return i;
			}
		}
	}
}

int GameManager::GetPlayery()
{
	int size = 32;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			if (allof[i].all[y]->Characteer == true)
			{
				return y;
			}
		}
	}
}

void GameManager::FightChoice(int i) 
{
}

int GameManager::FightSequence(Character *Mob,int x,int y)
{
	AllySprite(64, 0);
	bool endof = false;
	bool wintest = false;
	int unused = 0;
	while (!endof)
	{
		if (!CheckEnemis(&x, &y, &unused, &unused))
		{
			endof = true;
			break;
		}
		MoveCursor(64, 15);
		Player->ShowStat();

		MoveCursor(94, 15);
		Mob->ShowEstat();

		MoveCursor(64, 11);
		int i = FightMenu();

		switch (i)
		{
		case 0:
			Mob->takedmg(Player->DmgGet(),Mob->DefenseGet());
			MoveCursor(64, 20);
			if (allof[Mob->x].all[Mob->y]->Mob->IsDead())
			{
				wintest = true;
				endof = true;
				break;
			}
			Player->takedmg(Mob->DmgGet(), Player->DefenseGet());
			AskChar();
			MoveCursor(64, 20);
			if (Player->IsDead())
			{
				endof = true;
				break;
			}
			break;
		case 1:
			break;
		case 2:
		{
			MoveCursor(64, 11);
			int skill = SkillMenu();
			switch (skill)
			{
			case 0:
				Mob->takedmg(Player->DmgGet() + 5, Mob->DefenseGet());
				cout << "You use Slash";
				if (Mob->IsDead())
				{
					
					wintest = true;
					endof = true;
					break;
				}
				Player->takedmg(Mob->DmgGet(), Player->DefenseGet());
				if (Player->IsDead())
				{
					endof = true;
					break;
				}
				break;

			case 1:
				Player->takedmg(Mob->DmgGet(), Player->DefenseGet() + 5);
				if (Player->IsDead())
				{
					endof = true;
					break;
				}
				break;

			case 2:
				break;

			default:
				break;
			}
			break;
		}

		default:
			break;
		}
	}
	if (wintest)
	{
		Player->levelup();
		return 0;
	}
	else if (Player->IsDead())
	{
		return 1;
	}
	else
	{
		return 0;
	}

	
}

void GameManager::GetSpecter(int* x, int* Y)
{
	int size = 32;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			if (allof[i].all[y]->Mob->Specter == true)
			{
				*x = i;
				*Y = y;
			}
		}
	}

}

void GameManager::SpectreMove()
{
	
	int x = GetPlayerx();
	int y = GetPlayery();
	int Sx,Sy;
	GetSpecter(&Sx, &Sy);
	int beforex = Sx;
	int beforey = Sx;
	if (x > Sx)
	{
		if (Moveto(&Sx,&Sy, Sx - 1, Sy, false))
		{
			Sx -= 1;
		}
	}
	else
	{
		if (Moveto(&Sx, &Sy, Sx + 1, Sy, false))
		{
			Sx += 1;
		}
	}
	if (y > Sy)
	{
		if (Moveto(&Sx, &Sy, Sx, Sy-1, false))
		{
			Sy -= 1;
		}
	}
	else
	{
		if (Moveto(&Sx,&Sy, Sx, Sy+1, false))
		{
			Sy += 1;
		}
	}
	allof[Sx].all[Sy]->enemis = true;
	allof[beforex].all[beforey]->enemis = false;
	allof[Sx].all[Sy]->Mob = allof[beforex].all[beforey]->Mob;
	cout << allof[Sx].all[Sy]->Mob->AttackGet();
	allof[beforex].all[beforey]->Mob = NULL;
}

bool GameManager::Checkforwin()
{
	bool test = true;
	int size = 32;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			if (allof[y].all[i]->enemis == true)
			{
				test = true;
				if (allof[i].all[y]->Mob->IsDead())
				{
					allof[y].all[i]->enemis = false;
					
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			if (allof[i].all[y]->enemis == true)
			{
				test = false;
			}
		}
	}
	return test;
}