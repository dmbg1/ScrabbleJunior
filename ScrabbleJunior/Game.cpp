#include "Player.h"
#include "InputManagement.h"
#include "Board.h"
#include "Pool.h"
#include "outputs.h"

using namespace std;

int main() {
	int nPlayers; // Number of players
	Board board;	// Board where the game will be played

	board.readBoardFile();

	// Drawing the board many times in main and other parts of the code to refresh its view
	drawBoard(board); 
	
	// Filling the pool with board's mapped characters
	Pool pool(board.getChars());
	
	playerNumberInput(nPlayers);

	drawBoard(board);
	cout << endl;
	
	board.addPlayers(nPlayers, pool);

	drawGameInfo(board, pool);

	// Game Start :
	while (board.playersHavePieces())
	{
		for (Player player : board.getPlayers())
			board.gameTurn(player.getId(), pool);
	}

	drawBoard(board);

	showWinners(board);

	return 0;
}