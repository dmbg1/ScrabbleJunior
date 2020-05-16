#pragma once
#include "Player.h"
#include <time.h>

class Pool
{
public:
	void givePieces(Player player);
private:
	vector<char> pool_tiles;
};

