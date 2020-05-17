#pragma once
#include "Player.h"
#include "Board.h"
#include <time.h>

class Pool
{
public:
	Pool(Board b);
	void giveInitialPieces(Player &player);
private:
	vector<char> pool_tiles;
};

