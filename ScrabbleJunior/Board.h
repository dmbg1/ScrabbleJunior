#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gui.h"

using namespace std;

class Board
{
public:
	void readBoardFile();
	vector<char> getChars();
	vector<string> getCoords();
	map <string, char> getM();
	void mapBoard(vector<string> keys);
	void showBoard();
private:
	int size;
	vector<string> words;
	vector<string> coords;
	vector<char> oris;
	vector<char> chars; //contains the chars on the board (useful to pass to the pool)
	map<string, char> m;
};

