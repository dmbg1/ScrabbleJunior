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
	cout << endl << "Tiles in pool: " << pool.getPoolTiles().size() << endl;

	for (char c : pool.getPoolTiles())
		cout << c << endl;
	//GAME START


	while (board.playersHavePieces())
	{
		for (Player player : board.getPlayers())
		{
			board.gameTurn(player.getId(), pool);
			Sleep(500);
			clrscr();
			board.showBoard();
			board.showPlayersTiles();
			cout << endl << "Tiles in pool: " << pool.getPoolTiles().size() << endl;
			for (char c : pool.getPoolTiles())
				cout << c << endl;
		}
	}

	Sleep(500);
	clrscr();
	board.showBoard();

	vector<int> winners; //Contains ids of winners/winner;
	int maxScore = -1;
	int maxScorePlayerId = -1;
	for (Player player : board.getPlayers()) {
		if (player.getScore() > maxScore) {
			maxScore = player.getScore();
			maxScorePlayerId = player.getId();
			winners.clear();
			winners.push_back(player.getId());
		}
		else if (player.getScore() == maxScore)
			winners.push_back(player.getId());
	}
	if (winners.size() > 1)
		cout << "Winners with " << maxScore << " points:" << endl;
	for (int winner : winners)
		cout << "Player " << board.getPlayers()[winner - 1].getId() << endl;

	return 0;
}