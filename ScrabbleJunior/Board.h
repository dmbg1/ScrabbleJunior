#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "gui.h"
#include "Player.h"
#include "InputManagement.h"

using namespace std;

class Board
{
public:
	void readBoardFile(); // Reads a board file and saves the information it gives
	vector<char> getChars() const;
	vector<string> getCoords() const;
	map <string, char> getM() const;
	vector<Player> getPlayers() const;
	void addPlayers(const int n, Pool& pool);	// Adds n players and makes them draw 7 pieces from pool (Starting conditions)
	void mapBoard(vector<string> keys);	// Maps the board (fills m map)
	void showPlayersTiles() const; // Shows player Tiles
	void showBoard();	// Shows board
	bool playersHavePieces() const;	/* Checks if any of the players have pieces and returns 1 if at least one player has one piece 
									(keeps the game going) */
	void gameTurn(int playerId, Pool& p); // Treats player turns
	bool canPlay(Player p);	//Function that checks if it is possible for a player to make a move

private:
	int size;	// board size
	vector<string> words;	// words on the board
	vector<string> coords; /* will be useful for keeping track of the moves players can make (always have the coords of each word
						   where players can put a tile) */
	vector<char> oris;	// gives the orientations of each word
	vector<char> chars;	// contains the chars on the board (useful to pass to the pool tiles)
	map<string, char> m;	// contains the coordinates of each letter in the board	
	vector<Player> players;	// contains all the players using the board to play
};

