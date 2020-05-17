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

	Sleep(500);
	clrscr();

	board.showBoard();
	cout << endl;
	
	for (int i = 1; i <= nPlayers; i++) {
		players.push_back(Player(i));
		pool.giveInitialPieces(players[i - 1]);
		players[i - 1].showTiles();
	}
	board.setPlayers(players);
	return 0;
}