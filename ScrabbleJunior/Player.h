#pragma once

#include <vector>

using namespace std;

class Player
{
public:
	Player(int pId);
	void reshufleTwoTiles(vector<char> toReshufle);
	void addTile(char t);
	int getId();
private:
	vector<char> tiles;
	int id;
};

