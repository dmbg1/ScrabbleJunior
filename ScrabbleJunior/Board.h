#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gui.h"
#include "Player.h"

using namespace std;

class Board
{
public:
	void readBoardFile();
	vector<char> getChars() const;
	vector<string> getCoords() const;
	map <string, char> getM() const;
	void mapBoard(vector<string> keys);
	void showBoard();
	void setPlayers(vector<Player> p);
private:
	int size;
	vector<string> words;
	vector<string> coords;
	vector<char> oris;
	vector<char> chars; //contains the chars on the board (useful to pass to the pool)
	map<string, char> m;
	vector<Player> players;
};

