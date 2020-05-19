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
	void showBoard();	// Shows board
	void addWord(string word, char ori, string key);	// adds a word to the vector words
	bool isAddable(string word, char orientation, string key); //Checks if the word is addable to the board
	void readFile(const int wordsnum);	// Reads a file and selects a number (wordsnum) of random words from it to add to the board
	void createBoardFile() const;	// Makes a board representation file

private:
	vector<string> words; // words on the board
	vector<string> fileString;	//Saves the lines to put in the board file (except the first one)
	unsigned int size;	// Size of board
	map<string, char> m; // contains the coordinates of each letter in the board	
};

