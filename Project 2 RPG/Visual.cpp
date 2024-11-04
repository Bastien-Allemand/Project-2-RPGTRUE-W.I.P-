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

int CharaCreationMenu()
{

	int Ran = 0;
	const char* first = GREEN;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	const char* fourth = DEFAULT;
	while (true)
	{

		HideCursor();
		MoveCursor(0, 0);

		cout << "(Q,D)" << endl;
		cout << "Chose your Class:" << endl;
		cout << first << "+---------+" << second << "--------+" << third << "--------+ " << DEFAULT << endl;
		cout << first << "| Fighter |" << second << "  Mage  |" << third << "  Thief |" << DEFAULT << endl;
		cout << first << "+---------+" << second << "--------+" << third << "--------+" << DEFAULT << endl;

		int move = movement();
		switch (move)
		{
		case(' '):
			return Ran;
		case('q'):
			if (third == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				Ran = 1;
			}
			else if (second == GREEN)
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;

				Ran = 0;
			}
			else
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				Ran = 2;
			}
			break;

		case('d'):
			if (first == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				Ran = 1;
			}
			else if (second == GREEN)
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				Ran = 2;
			}
			else
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;
				Ran = 0;
			}
			break;

		default:
			continue;
		}
	}

}

int OptionMenu()
{
	int Ron = 0;
	const char* first = GREEN;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	const char* fourth = DEFAULT;
	while (true)
	{

		HideCursor();
		MoveCursor(0, 0);

		cout << "(Q,D,Space to Validate)" << endl;
		cout << "Menu:" << endl;
		cout << first << "+---------+" << second << "--------+" << third << "--------+ " << DEFAULT << endl;
		cout << first << "| Go back |" << second << "Nothing |" << third << "Nothing |" << DEFAULT << endl;
		cout << first << "+---------+" << second << "--------+" << third << "--------+" << DEFAULT << endl;

		int move = movement();
		switch (move)
		{
		case(' '):
			return Ron;
		case('q'):
			if (third == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				Ron = 1;
			}
			else if (second == GREEN)
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;

				Ron = 0;
			}
			else
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				Ron = 2;
			}
			break;

		case('d'):
			if (first == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				Ron = 1;
			}
			else if (second == GREEN)
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				Ron = 2;
			}
			else
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;
				Ron = 0;
			}
			break;

		default:
			continue;
		}
	}
}

int Fightmenu()
{

	int RU = 0;
	const char* first = GREEN;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	const char* fourth = DEFAULT;
	while (true)
	{
		
		HideCursor();
		MoveCursor(10,0);

		cout << "(Q,D,Space to Validate)" << endl;
		cout << "Menu:" << endl;
		cout << first << "+---------+" << second << "---------+" << third << "--------+ " << DEFAULT << endl;
		cout << first << "|  Fight  |" << second << "Item(WIP)|" << third << "Nothing |" << DEFAULT << endl;
		cout << first << "+---------+" << second << "---------+" << third << "--------+" << DEFAULT << endl;

		int move = movement();
		switch (move)
		{
		case(' '):
			return RU;
		case('q'):
			if (third == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				RU = 1;
			}
			else if (second == GREEN)
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;

				RU = 0;
			}
			else
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				RU = 2;
			}
			break;

		case('d'):
			if (first == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				RU = 1;
			}
			else if (second == GREEN)
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				RU = 2;
			}
			else
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;
				RU = 0;
			}
			break;

		default:
			continue;
		}
	}
}

void Colorising(tiles* allof, int y, int x)
{
	if (allof[x].all[y]->enemis == true)
	{
		cout << BRED << "  " << BDEFAULT;
	}
	else if (allof[x].all[y]->Characteer == true)
	{
		cout << BBLUE << "  " << BDEFAULT;
	}
	else
	{
		cout << BBROWN << "  " << BDEFAULT;
	}
}

void FRAME(tiles* allof)
{
	int size = 32;
	MoveCursor(0, 0);
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			Colorising(allof, y, i);
		}
		cout << BDEFAULT << endl;
	}
}

