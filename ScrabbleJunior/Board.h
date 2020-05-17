#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gui.h"
#include "Player.h"
#include "InputManagement.h"

using namespace std;

class Board
{
public:
	void readBoardFile();
	vector<char> getChars() const;
	vector<string> getCoords() const;
	map <string, char> getM() const;
	vector<Player> getPlayers() const;
	void setPlayers(vector<Player> p);
	void mapBoard(vector<string> keys);	
	void showPlayersTiles() const;
	void showBoard();
	bool playersHavePieces() const;	//Functions that checks if any of the players have pieces 
	void gameTurn(int playerId, Pool& p); //Function that treats player turns
	bool canPlay(Player p);	//Function that checks if it is possible for a player to make a move
private:
	int size;
	vector<string> words;
	vector<string> coords; //will be useful for keeping track of the moves players can make
	vector<char> oris;
	vector<char> chars; //contains the chars on the board (useful to pass to the pool)
	map<string, char> m;
	vector<Player> players;
};

