#include <iostream>
#include "Player.h"
#include "InputManagement.h"
#include "Board.h"
#include "Pool.h"

using namespace std;

int main() {
	int nPlayers;
	vector <Player> players;
	Board board;

	board.readBoardFile();
	Sleep(500);
	clrscr();
	board.showBoard();
	
	Pool pool(board.getChars());
	playerNumberInput(nPlayers);

	Sleep(500);
	clrscr();

	board.showBoard();
	cout << endl;
	
	for (int i = 1; i <= nPlayers; i++) {
		players.push_back(Player(i));
		players[i - 1].drawTilesFromPool(pool, 7);
	}

	board.setPlayers(players);
	board.showPlayersTiles();


	//GAME START

	string key;
	int tile;
	int playerNum = 0;
	char playerTile;

	while (pool.getPoolTiles().size() != 0)
	{
		int jogadas = 0;
		for (int i = 0; i < 2; i++)
		{
			cout << endl << "Player " << playerNum + 1 << " turn. Select a number of a tile: (0 to skip)" << endl;
			cin >> tile;
			cout << endl << "Select a Coordenate to place the tile: " << endl;
			cin >> key;

			if (tile != 0 || key != "0")
			{
				/*if (!isdigit(tile))
				{
					cout << endl << "Jogada Invalida" << endl;
					continue;
				}*/
				playerTile = board.getPlayers()[playerNum].getTiles()[tile - 1];
				//cout << endl << playerTile << endl;
				//cout << endl << board.getM()[key] << endl;

				if (playerTile != board.getM()[key])
				{
					cout << endl << "Jogada Invalida" << endl;
					continue;
				}

				//cout << endl << board.getM()[key] << endl;
				board.getPlayers()[playerNum].setTilesInBoard(key, playerTile);
				cout << endl << "000000000" << endl << board.getPlayers()[playerNum].getTilesPutInBoard()[key] << endl;
				jogadas++;
			}
		}

		board.getPlayers()[playerNum].drawTilesFromPool(pool, jogadas);

		playerNum++;
		if (playerNum > 3) playerNum = 0;

		Sleep(500);
		clrscr();
		board.showBoard();
		board.showPlayersTiles();
	}


		


	/*while (board.playersHavePieces()) {

	}*/

	return 0;
}