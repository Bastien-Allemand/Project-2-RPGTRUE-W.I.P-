#pragma once
class Character;

struct tilesId
{
	bool Characteer;
	bool enemis;
	Character* Mob;
	Character* Player;
};
struct tiles
{
	tilesId** all;
};
