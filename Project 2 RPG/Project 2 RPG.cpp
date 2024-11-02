#include "Utility.h"
#include "Menus.h"
#include "Color.h"
#include "Fighter.h"
#include "Mage.h"
#include "Thief.h"
#include "CharacterStat.h"
#include <conio.h>
#include <windows.h>
#include <iostream>


using namespace std;

const char* id(int y)
{
	int f = y % 2;
	if (f == 0)
	{
		return BORANGE;
	}
	else
	{
		return BBROWN;
	}
}

void makingofmap()
{

}
void FRAME()
{
	int size = 32;
	system("CLS");
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size + size; y++)
		{
			cout << id(y) << " @";
		}
		cout << BDEFAULT << endl;
		for (int y = 0; y < size + size; y++)
		{
			cout << id(y - 1) << "  ";
		}
		cout << BDEFAULT << endl;
	}
}
void CharacterCreation(int Class)
{
	CharacterStat* Player[1];
	switch (Class)
	{
	case(0):
		Player[0] = new Fighter(20, 4, 2);  //PV ATTACK DEFENSE
		cout << "Fighter Created" << endl;
		break;
	case(1):
		Player[0] = new Mage(10, 20, 4, 0); //MANA PV ATTACK DEFENSE
		cout << "Mage Created" << endl;

		break;
	case(2):
		Player[0] = new Thief(8, 20, 3, 1);
		cout << "Assasin created" << endl;
		break;
	default:
		break;
	}
	Player[0]->ShowStat();

}


int main()
{
	bool t = true;
	FullScreen();
	while (t == true)
	{


		int Y = Menusofopening();
		int T = 0;
		switch (Y)
		{
		case(0):

			CharacterCreation(CharaCreationMenu());
			t = false;
			FRAME();
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
