#include "Player.h"

Player::Player(int pId)
{
	id = pId;
}

void Player::reshufleTwoTiles(vector<char> toReshufle)
{

}

void Player::addTile(char t)
{
	tiles.push_back(t);
}

int Player::getId()
{
	return id;
}
