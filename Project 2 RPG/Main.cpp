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
	int K = 4;
	GameS->makingofmap();
	while (true)
	{


		int i = StartMenu();
		switch (i)
		{
		case(0):
		{
			
			GameS->CharacterCreation(CharacreationMenu());
			int Rounds = 0;
			GameS->FRAME();
			cout << Rounds;
			MoveCursor(64, 15);
			GameS->Player->ShowStat();
			int x = 31, y = 16;
			while (true)
			{
				char MoveC = AskChar();
				GameS->Cmoved(MoveC, &x, &y);
				int Ex;
				int Ey;
				bool test = GameS->CheckEnemis(&x, &y, &Ey, &Ex);
				Rounds++;
				GameS->FRAME();
				cout << Rounds;
				MoveCursor(64, 15);
				GameS->Player->ShowStat();
				if (test)
				{
					int i = GameS->FightSequence(*GameS->allof[Ex].all[Ey]->Mob);
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
						K--;
 						if (K == 0)
						{
							system("cls");
							cout << "WIN";
							AskChar();
							exit(0);
						}
					}
					ClearScreen(64, 0, 75, 21);
					
					GameS->FRAME();
					cout << Rounds;
					MoveCursor(64, 15);
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
