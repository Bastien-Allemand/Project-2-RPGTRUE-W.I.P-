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
			int x = 31, y = 16;
			while (true)
			{
				char MoveC = AskChar();
				GameS->Cmoved(MoveC, &x, &y);
				int Ex;
				int Ey;
				bool test = GameS->CheckEnemis(&x, &y, &Ey, &Ex);
				if (test)
				{
					GameS->FightSequence();
				}
				GameS->FRAME();

			}
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
