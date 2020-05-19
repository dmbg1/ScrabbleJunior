#include "outputs.h"

void drawBoard(Board board) {
	Sleep(500);
	clrscr();
	board.showBoard();
}

void drawGameInfo(Board board, Pool pool) {
	board.showPlayersTiles();
	cout << endl << "Tiles in pool: " << pool.getPoolTiles().size() << endl;
}

void showWinners(Board board) {
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
	else if (winners.size() == 1)
		cout << "Winner with " << maxScore << " points:" << endl;

	for (int winner : winners)
		cout << "Player " << board.getPlayers()[winner - 1].getId() << endl;
}