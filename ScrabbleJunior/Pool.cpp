#include "Pool.h"


Pool::Pool(Board b)
{
	for (string s : b.getWords())
		for (char c : s)
			pool_tiles.push_back(c);
}

void Pool::givePieces(Player player)
{
	int idx;  //index to be removed from the pool tiles and added to the player tiles
	srand(time(NULL));

	for (int i = 0; i < 7; i++) {
		idx = rand() % (pool_tiles.size() + 1);
		cout << idx << endl;
		player.addTile(pool_tiles[idx]);
		pool_tiles.erase(pool_tiles.begin() + idx);
	}
}
