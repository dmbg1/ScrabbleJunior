#include "Board.h"
#include "InputManagement.h"
#include "gui.h"
#include <iostream>

using namespace std;

int main() {
	int size; //Largura e comprimento
	string key;
	char ori;
	printf("BOARD BUILDER\n");
	sizeInput(size);
	int num = numWords();
	Board board(size);
	clrscr();
	board.showBoard();

	board.addWord("arroz", 'V', size);

	vector<string> words = board.readFile(num);

	vector<string>::iterator it;


	for (it = words.begin(); it < words.end(); it++)	// iterador que percorre vetor de palavras e preenche board
	{
		
		ori = orientationInput();
		board.addWord(*it, ori, size);
	}

	Sleep(500);
	clrscr();
	board.showBoard();
}