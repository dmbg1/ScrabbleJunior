#include "Player.h"

Player::Player(int pId)
{
	id = pId;
	score = 0;
}

void Player::reshufleTwoTiles(Pool& p)
{
	int tile1, tile2;
	cout << "Choose two of your tiles to reshufle\n" << endl;
	cout << "__________________________________________________\n" << endl;
	for (int i = 0; i < tiles.size(); i++)
	{
		cout << i + 1 << " - " << tiles[i] << endl;
	}

	while (1)
	{
		cout << endl << "Tile 1 : ";
		cin >> tile1;
		if (tile1 < 1 && tile1 > tiles.size() + 1 && !isdigit(tile1)) {
			cout << endl << "Invalid tile number" << endl;
			continue;
		}
		cout << endl << "Tile 2 : ";
		cin >> tile2;
		if (tile2 < 1 && tile2 > tiles.size() + 1 && !isdigit(tile2) && tile2 == tile1) {
			cout << endl << "Invalid tile number" << endl;
			continue;
		}
		break;
	}

	p.addTileToPool(tile1);
	p.addTileToPool(tile2);

	tiles.erase(tiles.begin() + tile1 - 1);
	tiles.erase(tiles.begin() + tile2 - 1);

	drawTilesFromPool(p, 2);
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
		cout << i + 1 << "-" << tiles[i] << "; ";

	setcolor(WHITE);

	cout << endl;
}

int Player::getId() const
{
	return id;
}

vector<char> Player::getTiles() const
{
	return tiles;
}

map<string, char> Player::getTilesPutInBoard() const
{
	return tilesInBoard;
}

void Player::drawTilesFromPool(Pool &pool, int n)
{
	int idx;  //index to be removed from the pool tiles and added to the player tiles
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		if (pool.getPoolTiles().size() == 0)
			break;
		idx = rand() % pool.getPoolTiles().size();
		addTile(pool.getPoolTiles()[idx]);
		pool.removeTileFromPool(idx);
	}
}

void Player::setTilesInBoard(string key, char c)
{
	tilesInBoard[key] = c;
}