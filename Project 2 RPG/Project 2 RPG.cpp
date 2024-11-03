#include "Utility.h"
#include "Tils.h"
#include "Menus.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

void PlayGame(tils* allof,GameManager* GameS)
{

	makingofmap(allof,GameS);
	int x = 31;
	int y = 16;
	CharacterCreation(CharaCreationMenu());

	FRAME(allof);
	
	while (true)
	{
		char cMove = movement();
		Cmoved(allof, cMove, &x, &y);
		FRAME(allof);
	}


}

int main()
{
	GameManager Games;
	tils* allof = new tils[32];

	for (int i = 0; i < 32; i++)
	{
		allof[i].all = new tilsId * [32];
		for (int j = 0; j < 32; j++)
		{
			allof[i].all[j] = (tilsId*)malloc (sizeof(tilsId));
		}
	}
	bool t = true;
	FullScreen();


 	while (t == true)
	{


		int Y = Menusofopening();
		int T = 0;
		switch (Y)
		{
		case(0):
			t = false;
			PlayGame(allof,&Games);
			break;
		case(1):
			ClearFullScreen();
			T = OptionMenu();
			ClearFullScreen();
			break;
		case(2):
			cout << "MOI J'AI TOUT FAIT";
			break;
		default:
			break;
		}
	}
	return 0;

}
