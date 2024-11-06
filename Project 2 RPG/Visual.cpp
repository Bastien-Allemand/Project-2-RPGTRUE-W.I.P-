#include "Visual.h"
#include "Color.h"
#include "Utility.h"
#include "Character.h"
#include "GameManager.h"
#include "Tiles.h"
#include <iostream>
using namespace std;

int StartMenu()
{
	int i = 0;
	DisplayeofStart(i);
	while (true)
	{


		if (GraphicKey(&i))
		{
			return i;
		}
		else
		{
			DisplayeofStart(i);
		}
	}
}
void DisplayeofStart(int i)
{
	const char* first = DEFAULT;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	if (i == 0)
	{
		first = GREEN;
		second = DEFAULT;
		third = DEFAULT;
	}
	if (i == 1)
	{
		first = DEFAULT;
		second = GREEN;
		third = DEFAULT;
	}
	if (i == 2)
	{
		first = DEFAULT;
		second = DEFAULT;
		third = GREEN;
	}
	HideCursor();
	MoveCursor(0, 0);
	cout << "(Q,D)" << endl;
	cout << first << "+------+" << second << "--------+" << third << "--------+ " << DEFAULT << endl;
	cout << first << "| Play |" << second << " option |" << third << " Credit |" << DEFAULT << endl;
	cout << first << "+------+" << second << "--------+" << third << "--------+" << DEFAULT << endl;
}

int CharacreationMenu()
{
	int i = 0;
	DisplayCharacreation(i);
	while (true)
	{
		if (GraphicKey(&i))
		{
			return i;
		}
		else
		{
			DisplayCharacreation(i);
		}
	}
}
void DisplayCharacreation(int i)
{
	const char* first = DEFAULT;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	const char* fourth = DEFAULT;
	if (i == 0)
	{
		first = GREEN;
		second = DEFAULT;
		third = DEFAULT;
	}
	if (i == 1)
	{
		first = DEFAULT;
		second = GREEN;
		third = DEFAULT;
	}
	if (i == 2)
	{
		first = DEFAULT;
		second = DEFAULT;
		third = GREEN;
	}
	HideCursor();
	MoveCursor(0, 0);
	cout << "(Q,D)" << endl;
	cout << first << "+---------+" << second << "--------+" << third << "--------+ " << DEFAULT << endl;
	cout << first << "| Fighter |" << second << "  Mage  |" << third << " Assasin|" << DEFAULT << endl;
	cout << first << "+---------+" << second << "--------+" << third << "--------+" << DEFAULT << endl;

}

int OptionMenu()
{
	int i = 0;
	OptionDisplay(i);
	while (true)
	{


		if (GraphicKey(&i))
		{
			return i;
		}
		else
		{
			OptionDisplay(i);
		}
	}
}
void OptionDisplay(int i)
{
	const char* first = DEFAULT;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	if (i == 0)
	{
		first = GREEN;
		second = DEFAULT;
		third = DEFAULT;
	}
	if (i == 1)
	{
		first = DEFAULT;
		second = GREEN;
		third = DEFAULT;
	}
	if (i == 2)
	{
		first = DEFAULT;
		second = DEFAULT;
		third = GREEN;
	}
	HideCursor();
	MoveCursor(0, 0);

	cout << "(Q,D,Space to Validate)" << endl;
	cout << "Menu:" << endl;
	cout << first << "+---------+" << second << "--------+" << third << "--------+ " << DEFAULT << endl;
	cout << first << "| Go back |" << second << "Nothing |" << third << "Nothing |" << DEFAULT << endl;
	cout << first << "+---------+" << second << "--------+" << third << "--------+" << DEFAULT << endl;

}

int FightMenu()
{
	int i = 0;
	int xfix = getCursorX();
	int yfix = getCursorY();
	FightDisplay(xfix,yfix,i);
	while (true)
	{


		if (GraphicKey(&i))
		{
			return i;
		}
		else
		{
			FightDisplay(xfix,yfix, i);
		}
	}
}
void FightDisplay(int xfix,int yfix ,int i)
{
	const char* first = DEFAULT;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	if (i == 0)
	{
		first = GREEN;
		second = DEFAULT;
		third = DEFAULT;
	}
	if (i == 1)
	{
		first = DEFAULT;
		second = GREEN;
		third = DEFAULT;
	}
	if (i == 2)
	{
		first = DEFAULT;
		second = DEFAULT;
		third = GREEN;
	}
	HideCursor();
	
	MoveCursor(xfix+6, yfix);

	cout << "(Q,D,Space to Validate)"; MoveCursor(xfix, yfix);
	cout << "Menu:"; MoveCursor(xfix, yfix+1);
	cout << first << "+---------+" << second << "---------+" << third << "--------+ " << DEFAULT; MoveCursor(xfix, yfix+2);
	cout << first << "|  Fight  |" << second << "Item(WIP)|" << third << "Nothing |" << DEFAULT; MoveCursor(xfix, yfix+3);
	cout << first << "+---------+" << second << "---------+" << third << "--------+" << DEFAULT; MoveCursor(xfix, yfix+4);

}

