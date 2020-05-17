#pragma once

#include <vector>
#include <map>
#include <iostream>
#include "gui.h"

using namespace std;

class Player
{
public:
	Player(int pId);
	void reshufleTwoTiles(vector<char> toReshufle);
	void addTile(char t);
	void showTiles();
	int getId() const;
	map<string, char> getTilesPutInBoard() const;
private:
	vector<char> tiles;
	map<string, char> tilesInBoard; //Contains the tiles put in the board
	int id;
	int score;
};

