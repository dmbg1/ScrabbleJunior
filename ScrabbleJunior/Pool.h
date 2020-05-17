#pragma once
#include <vector>
#include <time.h>

using namespace std;

class Pool
{
public:
	Pool(vector<char> tiles);
	vector<char> getPoolTiles() const;
	void addTileToPool(char c);
	void removeTileFromPool(int idx);
private:
	vector<char> pool_tiles;
};

