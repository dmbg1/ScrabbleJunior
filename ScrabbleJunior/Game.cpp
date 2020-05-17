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
	
	Pool pool(board);
	playerNumberInput(nPlayers);
	
	for (int i = 1; i <= nPlayers; i++) {
		players.push_back(Player(i));
		pool.givePieces(players[i - 1]);
		players[i - 1].showTiles();
	}

	return 0;
}