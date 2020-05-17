#include "Pool.h"


Pool::Pool(Board b)
{
	pool_tiles = b.getChars();
}

void Pool::givePieces(Player &player)
{
	int idx;  //index to be removed from the pool tiles and added to the player tiles
	srand(time(NULL));

	for (int i = 0; i < 7; i++) {
		idx = rand() % pool_tiles.size();
		player.addTile(pool_tiles[idx]);
		pool_tiles.erase(pool_tiles.begin() + idx);
	}
}
