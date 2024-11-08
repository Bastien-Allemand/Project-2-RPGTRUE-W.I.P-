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
	reaper = (Reaper**)malloc(sizeof(Reaper) * 2);
	golem = new Golem(10, 5, 3);
	spectre = new Spectre(10, 3, 1);
	reaper[0] = new Reaper(10, 8, 2);
	reaper[1] = new Reaper(10, 8, 2);
	
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
		allof[x].all[y]->Mob->ColorE();
		cout << "  " << BDEFAULT;
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
				allof[x].all[y]->Mob = golem;
			}
			if (x == 20 && y == 10)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = spectre;
			}
			if (x == 10 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = reaper[0];
			}
			if (x == 20 && y == 20)
			{
				allof[x].all[y]->enemis = true;
				allof[x].all[y]->Mob = reaper[1];
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
		CheckMove(x, y, *x - 1, *y, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	case('q'):
		CheckMove(x, y, *x, *y-1, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	case('s'):
		CheckMove(x, y, *x + 1, *y, true);
		allof[*x].all[*y]->Characteer = true;
		break;
	case('d'):
		CheckMove(x, y, *x, *y+1, true);
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
			if (CheckMove(&X, &Y, X, Y, false))
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
	int specterX, specterY;
	GetSpecter(&specterX, &specterY);
  	if (allof[specterX].all[specterY]->Mob->HealthGet() <= 0)
	{
		allof[specterX].all[specterY]->enemis = false;
	}
	AllySprite(64, 0);

	bool endof = false;
	bool wintest = false;
	int unused = 0;
	bool isSpectre = false;
	if (Mob == spectre)
	{
		isSpectre = true;
	}

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
			if (isSpectre)
			{
				if (Mob != spectre)
				{

				}
				int specterX, specterY;
				GetSpecter(&specterX, &specterY);
				Mob = allof[specterX].all[specterY]->Mob;
			}
				Mob->takedmg(Player->DmgGet(), Mob->DefenseGet());
				if (isSpectre)
				{
					if (Mob != spectre)
					{

					}
					int specterX, specterY;
					GetSpecter(&specterX, &specterY);
					Mob = allof[specterX].all[specterY]->Mob;
				}
				MoveCursor(64, 20);
   				if (Mob->IsDead())
				{
					wintest = true;
					endof = true;
					break;
				}
				Player->takedmg(Mob->DmgGet(), Player->DefenseGet());
				if (isSpectre)
				{
					if (Mob != spectre)
					{

					}
					int specterX, specterY;
					GetSpecter(&specterX, &specterY);
					Mob = allof[specterX].all[specterY]->Mob;
				}
				AskChar();
	
			MoveCursor(64, 20);
			if (Player->IsDead())
			{
				endof = true;
				break;
			}
			if (isSpectre)
			{
				endof = true;
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
	FRAME();
	int xe = GetPlayerx();
	int ye = GetPlayery();
	if (isSpectre)
	{
		return 0;
	}
	if (wintest)
	{
		Player->levelup();
		return 0;
	}
	else if (allof[x].all[y]->Player->IsDead())
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
	int size = 31;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			if (allof[i].all[y]->Mob == spectre)
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
	int Sx, Sy;
	GetSpecter(&Sx, &Sy);
	int Newx = Sx, Newy = Sy;
	if (x > Sx)
	{
		if (CheckMove(&x, &y, Sx - 1, Sy, false))
		{
			int Newx = Sx - 1;
		}
	}
	if (x < Sx)
	{
		if (CheckMove(&x, &y, Sx + 1, Sy, false))
		{
			int Newx = Sx + 1;
		}
	}
	if (y > Sy)
	{
		if (CheckMove(&x, &y, Sx, Sy - 1, false))
		{
			Newy = Sy - 1;
		}
	}
	if (y < Sy)
	{
		if (CheckMove(&x, &y, Sx, Sy + 1, false))
		{
			Newy = Sy + 1;
		}
	}
	allof[Sx].all[Sy]->enemis = false;
	allof[Newx].all[Newy]->enemis = true;
	if (allof[Sx].all[Sy]->Mob->IsDead())
	{
		allof[Newx].all[Newy]->enemis = false;
	}
	allof[Newx].all[Newy]->Mob = allof[Sx].all[Sy]->Mob;
	FRAME();
}

bool GameManager::Checkforwin()
{
	bool test = false;
	int size = 32;
	if (allof[10].all[10]->Mob->IsDead())
	{
		allof[10].all[10]->enemis = false;
		test = true;
	}
	if (allof[20].all[20]->Mob->IsDead())
	{
		allof[20].all[20]->enemis = false;
	}
	if (allof[10].all[20]->Mob->IsDead())
	{
		allof[10].all[20]->enemis = false;
	}
	int specterX, specterY;
	GetSpecter(&specterX, &specterY);
	if (allof[specterX].all[specterY]->Mob->IsDead())
	{
		allof[specterX].all[specterY]->enemis = false;
		test = true;
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

