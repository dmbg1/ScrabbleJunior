#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <numeric>
#include <algorithm>
#include <assert.h>
#include <list>
#include "gui.h"

using namespace std;

class Board
{
public:
	Board(unsigned int s);
	unsigned int getSize() const;
	map<string, char> getM() const;
	void showBoard();
	void addWord(string key, string word, char orientation);
	vector<string> readFile(int wordsnum);

private:
	unsigned int size;
	map<string, char> m;
};

