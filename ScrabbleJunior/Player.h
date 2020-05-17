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
	void reshufleTiles(Pool &p);	//Function that reshufles two or 1 of the tiles of the players according to the disponibility of the pool
	void addTile(char t);
	void showTiles();	//function that shows player's tiles
	int getId() const;
	vector<char> getTiles() const;
	map<string, char> getTilesPutInBoard() const; //gets tilesInBoard
	void drawTilesFromPool(Pool& pool, int n);
	void addTilesInBoard(string key, char c);	//inserts the pair {key, c} to the map tilesInBoard
	void incrementScore();
	void eraseTile(int idx);	//Erases value in index idx of the player's tiles
	int getScore() const;
private:
	vector<char> tiles;
	map<string, char> tilesInBoard; //Contains the tiles that the player placed in the board
	int id;
	int score;
};

