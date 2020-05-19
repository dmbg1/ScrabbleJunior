#pragma once
#include <vector>
#include <time.h>

using namespace std;

class Pool
{
public:
	Pool(vector<char> tiles);
	vector<char> getPoolTiles() const;
	void addTileToPool(const char tile);	// Adds a tile to the pool
	void removeTileFromPool(const int idx);	// Removes a tile from pool
private:
	vector<char> pool_tiles;
};

