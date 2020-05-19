#include "Player.h"

Player::Player(const int pId)
{
	id = pId;
	score = 0;
}

void Player::reshufleTiles(Pool& p)
{
	int tile1, tile2;
	if(p.getPoolTiles().size() >= 2)
	{
		cout << endl << "Choose two of your tiles to reshufle\n" << endl;
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

		p.addTileToPool(tiles[tile1 - 1]);
		p.addTileToPool(tiles[tile2 - 1]);

		if (tile1 < tile2)
		{
			int d;
			d = tile1;
			tile1 = tile2;
			tile2 = d;
		}

		eraseTile(tile1 - 1);
		eraseTile(tile2 - 1);

		drawTilesFromPool(p, 2);
	}
	else if (p.getPoolTiles().size() == 1) {

		cout << "Choose one of your tiles to reshufle (only one available in pool)\n" << endl;
		cout << "__________________________________________________\n" << endl;
		for (int i = 0; i < tiles.size(); i++)
		{
			cout << i + 1 << " - " << tiles[i] << endl;
		}

		while (1)
		{
			cout << endl << "Tile: ";
			cin >> tile1;
			if (tile1 < 1 && tile1 > tiles.size() + 1 && !isdigit(tile1)) {
				cout << endl << "Invalid tile number" << endl;
				continue;
			}
			break;
		}

		p.addTileToPool(tiles[tile1 - 1]);

		eraseTile(tile1 - 1);

		drawTilesFromPool(p, 1);
	}
}

void Player::addTile(const char t)
{
	tiles.push_back(t);
}

void Player::showTiles()
{
	cout << "Player " << id << " tiles with score = " << score << " : ";
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

void Player::drawTilesFromPool(Pool &pool, const int n)
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

void Player::addTileInBoard(const string coord, const char tile)
{
	tilesInBoard[coord] = tile;
}

void Player::incrementScore()
{
	score++;
}

void Player::eraseTile(const int idx)
{
	tiles.erase(tiles.begin() + idx);
}

int Player::getScore() const
{
	return score;
}
