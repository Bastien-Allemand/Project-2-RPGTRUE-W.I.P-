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

	makingofmap(allof, GameS);
	while (true)
	{


		int i = StartMenu();
		switch (i)
		{
		case(0):
		{
			FRAME(allof);
			int x = 31, y = 16;
			while (true)
			{
				char MoveC = movement();
				Cmoved(allof, MoveC, &x, &y);
				int Ex;
				int Ey;
				bool test = CheckEnemis(&x, &y, allof, &Ey, &Ex);

				FRAME(allof);

			}
		}
		case(1):
			ClearFullScreen();
			MoveCursor(0, 0);
			cout << "Settings";
			while (movement() != ' ')
			{
				
			}
			ClearFullScreen();
			break;
		case(2):
			ClearFullScreen();
			MoveCursor(0, 0);
			cout << "MEEEEEEEE";
			while (movement() != ' ')
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
