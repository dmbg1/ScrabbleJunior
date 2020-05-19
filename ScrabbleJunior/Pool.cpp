#include "Pool.h"

Pool::Pool(const vector<char> tiles)
{
	pool_tiles = tiles;
}

vector<char> Pool::getPoolTiles() const
{
	return pool_tiles;
}

void Pool::addTileToPool(const char tile)
{
	pool_tiles.push_back(tile);
}

void Pool::removeTileFromPool(const int idx) {
	pool_tiles.erase(pool_tiles.begin() + idx);
}