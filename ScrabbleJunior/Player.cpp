#include "Player.h"

Player::Player(int pId)
{
	id = pId;
	score = 0;
}

void Player::reshufleTwoTiles(vector<char> toReshufle)
{

}

void Player::addTile(char t)
{
	tiles.push_back(t);
}

void Player::showTiles()
{
	cout << "Player " << id << " tiles: ";
	if (id == 1)
		setcolor(BLUE);
	else if (id == 2)
		setcolor(RED);
	else if (id == 3)
		setcolor(GREEN);
	else if (id == 4)
		setcolor(YELLOW);

	for (int i = 0; i < tiles.size(); i++)
		cout << tiles[i] << "; ";

	setcolor(WHITE);

	cout << endl;
}

int Player::getId() const
{
	return id;
}

map<string, char> Player::getTilesPutInBoard() const
{
	return tilesInBoard;
}
