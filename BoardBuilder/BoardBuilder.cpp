#include "Board.h"
#include "InputManagement.h"
#include "gui.h"
#include <iostream>

using namespace std;

int main() {
	int size; //Largura e comprimento
	printf("BOARD BUILDER\n");
	sizeInput(size);
	int num = numWords();
	Board board(size);
	clrscr();
	board.showBoard();
	board.addWord("Aa", "arroz", 'V');
	Sleep(500);
	clrscr();
	board.showBoard();
	board.readFile(num);
}