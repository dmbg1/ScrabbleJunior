#pragma once

#include <map>
#include "Pool.h"
#include "gui.h"

using namespace std;

class Player
{
public:
	Player(const int pId);
	void reshufleTiles(Pool &p);	// Reshufles two or 1 of the tiles of the players according to the disponibility of the pool
	void addTile(const char t);	// Adds a new tile to the player's set
	void showTiles();	// Shows player's tiles
	int getId() const;
	vector<char> getTiles() const;
	map<string, char> getTilesPutInBoard() const;	// Gets tilesInBoard
	void drawTilesFromPool(Pool& pool, const int n);	// Draws n tiles from pool
	void addTileInBoard(const string coord, const char tile);	// Used to add a tile to the board in a certain coord
	void incrementScore();
	void eraseTile(const int idx);	// Erases value in index idx of the player's tiles
	int getScore() const;
private:
	vector<char> tiles;	// Set of player tiles
	map<string, char> tilesInBoard; // Contains the tiles that the player has already placed in the board
	int id;	// Player identifier 
	int score;
};

