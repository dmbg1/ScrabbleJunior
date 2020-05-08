#pragma once
#include <map>
#include <string>
#include <iostream>
#include <sstream>
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

private:
	unsigned int size;
	map<string, char> m;
};

