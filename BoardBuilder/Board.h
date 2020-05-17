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
	vector<string> getWords() const;
	unsigned int getSize() const;
	map<string, char> getM() const;
	void showBoard();
	void addWord(string word, char ori, string key);
	bool isAddable(string word, char orientation, string key); //Checks if the word is addable to the board
	void readFile(int wordsnum);
	void WriteToFile();

private:
	vector<string> words;
	vector<string> fileString;	//Saves the lines to put in the board file (except the first one)
	unsigned int size;
	map<string, char> m;
};

