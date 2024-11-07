#include "Utility.h"
#include "Tiles.h"
#include "Visual.h"
#include "GameManager.h"
#include "Color.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

void PlayAgain();

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
				int Ex = x;
				int Ey = y;
				bool test = GameS->CheckEnemis(&x, &y, &Ey, &Ex);
				Rounds++;
				GameS->FRAME();
				cout << Rounds;
				MoveCursor(64, 15);
				GameS->Player->ShowStat();
				if (test)
				{

					int i = GameS->FightSequence(GameS->allof[Ex].all[Ey]->Mob,x,y);
					if (i == 1)
					{
						system("cls");
						PlayAgain();
					}
					ClearScreen(64, 0, 75, 21);
					
					GameS->FRAME();
					cout << Rounds;
					MoveCursor(64, 15);
					GameS->Player->ShowStat();
				}
			if (GameS->Checkforwin())
			{
				system("CLS");
				cout << SGREEN << "YOU WIN" << SDEFAULT;

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
	srand(time(0));
	GameManager* Games = GameManager::GetInstance();
	FullScreen();
	PlayGame(Games->allof, Games);
	return 0;

}

void PlayAgain()
{
	int replay;
	cout << " You Lose!" << endl;
	cout << "Play Again?(0),(1)" << endl;
	cin >> replay;
	if (replay == 0)
	{
		main();
	}
	else
	{
		cout << "GOOD BYE :D";
	}
}