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

	board.addWord("arroz");

	Sleep(500);
	clrscr();
	board.showBoard();
	board.readFile(num);

	vector<string> words = board.getWords();

	for (int i = 0; i < words.size(); i++)	// iterador que percorre vetor de palavras e preenche board
	{
		cout << endl << words[i] << ":";

		board.addWord(words[i]);
		Sleep(500);
		clrscr();
		board.showBoard();
	}

	board.WriteToFile();
}