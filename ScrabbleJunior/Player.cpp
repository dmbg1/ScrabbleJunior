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

	for (int i = 0; i < tiles.size(); i++)
		cout << tiles[i] << "; ";

	cout << endl;
}

int Player::getId()
{
	return id;
}
