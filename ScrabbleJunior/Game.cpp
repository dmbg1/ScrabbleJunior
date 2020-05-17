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

	/*while (board.playersHavePieces()) {

	}*/

	return 0;
}