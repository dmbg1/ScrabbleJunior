#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Player
{
public:
	Player(int pId);
	void reshufleTwoTiles(vector<char> toReshufle);
	void addTile(char t);
	void showTiles();
	int getId();
private:
	vector<char> tiles;
	int id;
	int score;
};

