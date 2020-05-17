#include "Pool.h"

Pool::Pool(vector<char> tiles)
{
	pool_tiles = tiles;
}

vector<char> Pool::getPoolTiles() const
{
	return pool_tiles;
}

void Pool::addTileToPool(char c)
{
	pool_tiles.push_back(c);
}

void Pool::removeTileFromPool(int idx) {
	pool_tiles.erase(pool_tiles.begin() + idx);
}