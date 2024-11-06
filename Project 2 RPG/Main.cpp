#include "Utility.h"
#include "Tiles.h"
#include "Visual.h"
#include "GameManager.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

void PlayGame(tiles* allof,GameManager* GameS)
{
	GameS->makingofmap();
	while (true)
	{


		int i = StartMenu();
		switch (i)
		{
		case(0):
		{
			
			GameS->CharacterCreation(CharacreationMenu());
			GameS->FRAME();
			MoveCursor(64, 17);
			GameS->Player->ShowStat();
			int x = 31, y = 16;
			while (true)
			{
				char MoveC = AskChar();
				GameS->Cmoved(MoveC, &x, &y);
				int Ex;
				int Ey;
				bool test = GameS->CheckEnemis(&x, &y, &Ey, &Ex);
				GameS->FRAME();
				MoveCursor(64, 17);
				GameS->Player->ShowStat();
				if (test)
				{
					EnemisClass* enemy = GameS->allof[Ex].all[Ey]->Mob;
					int i = GameS->FightSequence(*enemy);
					if (i == 1)
					{
						system("cls");
						cout << "GAME OVER";
						AskChar();
						exit(0);
					}
					else
					{
						
						GameS->allof[Ey].all[Ex]->enemis = false;
					}
					ClearScreen(64, 0, 75, 20);
					GameS->FRAME();
					MoveCursor(64, 17);
					GameS->Player->ShowStat();
				}
				

			}
			break;
		}
		case(1):
			ClearFullScreen();
			MoveCursor(0, 0);
			while (OptionMenu() != 0)
			{

			}
			ClearFullScreen();
			break;
		case(2):
			ClearFullScreen();
			MoveCursor(0, 0);
			cout << "MEEEEEEEE";
			while (AskChar() != ' ')
			{
				
			}
			ClearFullScreen();
			break;
		default:
			break;
		}
	}


}

int main()
{
	GameManager Games;
	FullScreen();
	PlayGame(Games.allof, &Games);
	return 0;

}
