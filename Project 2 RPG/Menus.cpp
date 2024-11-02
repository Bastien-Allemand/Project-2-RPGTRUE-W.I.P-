#include "Menus.h"
#include "Color.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int Menusofopening()
{
	int Run = 0;
	const char* first = GREEN;
	const char* second = DEFAULT;
	const char* third = DEFAULT;
	while (true)
	{
		HideCursor();
		MoveCursor(0, 0);
		cout << "(Q,D)" << endl;
		cout << first << "+------+" << second << "--------+" << third << "--------+ " << DEFAULT << endl;
		cout << first << "| Play |" << second << " option |" << third << " Credit |" << DEFAULT << endl;
		cout << first << "+------+" << second << "--------+" << third << "--------+" << DEFAULT << endl;
		int move = movement();
		switch (move)
		{
		case(' '):
			return Run;
		case('q'):
			if (third == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				Run = 1;
			}
			else if (second == GREEN)
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;

				Run = 0;
			}
			else
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				Run = 2;
			}
			break;

		case('d'):
			if (first == GREEN)
			{
				first = DEFAULT;

				second = GREEN;

				third = DEFAULT;
				Run = 1;
			}
			else if (second == GREEN)
			{
				first = DEFAULT;

				second = DEFAULT;

				third = GREEN;
				Run = 2;
			}
			else
			{
				first = GREEN;

				second = DEFAULT;

				third = DEFAULT;
				Run = 0;
			}
			break;
		default:
			continue;
		}
	}

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
