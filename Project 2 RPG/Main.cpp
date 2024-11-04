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
	FRAME(allof);
	int x = 31, y = 16;
	while (true)
	{
		char MoveC = movement();
		Cmoved(allof, MoveC, &x, &y);
		bool test = CheckEnemis(&x,&y,allof);

		if (test)
		{
			cout << "YES";
		}
		FRAME(allof);

	}

}

int main()
{
	GameManager Games;
	FullScreen();
	PlayGame(Games.allof, &Games);
	return 0;

}
