#include "Color.h"
#include <iostream>
#include "Sprite.h"
#include "Utility.h"
using namespace std;




void AllySprite(int x,int y)
{
	MoveCursor(x, y);
	cout << "    " << BBLACK << "      " << BDEFAULT << " " << BBLACK << "      " << "    " << BDEFAULT;
	MoveCursor(x, y+1);
	cout << "  " << BBLACK << "  " << BRED << DIMON << "      " << DIMOFF << BBLACK << "  " << BRED << "      " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+2);
	cout << BBLACK << "  " << BRED << DIMON << "      " << DIMOFF << "            " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+3);
	cout << BBLACK << "  " << BRED << DIMON << "    " << DIMOFF << "              " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+4);
	cout << BBLACK << "  " << BRED << DIMON << "  " << DIMOFF << "                " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+5);
	cout << "  " << BBLACK << "  " << BRED << "              " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+6);
	cout << "    " << BBLACK << "  " << BRED << "          " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+7);
	cout << "      " << BBLACK << "  " << BRED << "      " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+8);
	cout << "        " << BBLACK << "  " << BRED << "  " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+9);
	cout << "          " << BBLACK << "  " << BDEFAULT;
	MoveCursor(x, y+10);
}
void EnemisSprite()
{
	cout << "AHHHHHHHHHHHHHHH";
}