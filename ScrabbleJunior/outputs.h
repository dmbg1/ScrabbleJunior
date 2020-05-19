#pragma once
#include "Board.h"

// Shows board
void drawBoard(Board board);

// Shows game information(player scores, player tiles, pool size) 
void drawGameInfo(Board board, Pool pool);

// Shows the winners/winner of the game
void showWinners(Board board);
