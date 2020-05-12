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

	board.addWord("arroz", 'V');

	Sleep(500);
	clrscr();
	board.showBoard();

	vector<string> words = board.readFile(num);

	for (int i = 0; i < words.size(); i++)	// iterador que percorre vetor de palavras e preenche board
	{
		cout << endl << words[i] << ":";
		ori = orientationInput();
		if (ori == '0')
			continue;

		board.addWord(words[i], ori);
		Sleep(500);
		clrscr();
		board.showBoard();
	}
}