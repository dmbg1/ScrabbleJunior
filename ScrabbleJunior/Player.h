#pragma once

#include <vector>
#include <map>
#include <iostream>
#include "Pool.h"
#include "gui.h"

using namespace std;

class Player
{
public:
	Player(int pId);
	void reshufleTwoTiles(Pool &p);
	void addTile(char t);
	void showTiles();
	int getId() const;
	vector<char> getTiles() const;
	map<string, char> getTilesPutInBoard() const;
	void drawTilesFromPool(Pool& pool, int n);
	void setTilesInBoard(string key, char c);
private:
	vector<char> tiles;
	map<string, char> tilesInBoard; //Contains the tiles put in the board
	int id;
	int score;
};

