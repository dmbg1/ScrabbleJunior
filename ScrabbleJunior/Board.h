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
	vector<string> getWords();
	map <string, char> getM();
	void mapBoard();
	void showBoard();
private:
	int size;
	vector<string> words;
	vector<string> coords;
	vector<char> oris;
	map<string, char> m;
};

