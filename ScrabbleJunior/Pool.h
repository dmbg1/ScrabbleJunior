#pragma once
#include "Player.h"
#include "Board.h"
#include <time.h>

class Pool
{
public:
	Pool(Board b);
	void givePieces(Player player);
private:
	vector<char> pool_tiles;
};

