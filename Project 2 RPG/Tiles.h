#pragma once
class EnemisClass;
class Character;

struct tilesId
{
	bool Characteer;
	bool enemis;
	EnemisClass* Mob;
	Character* Player;
};
struct tiles
{
	tilesId** all;
};
