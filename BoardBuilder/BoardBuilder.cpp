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
	Board board = Board();
	clrscr();
	
	board.setSize(size);
	board.showBoard();

	board.addWord("arroz", 'V', "Aa");

	Sleep(500);
	clrscr();
	board.showBoard();
	board.readFile(num);

	vector<string> words = board.getWords();

	for (int i = 0; i < words.size(); i++)	// iterador que percorre vetor de palavras e preenche board
	{
		cout << endl << words[i] << ":";

		ori = orientationInput();
		key = keyInput();

		board.addWord(words[i], ori, key);
		Sleep(500);
		clrscr();
		board.showBoard();
	}

	board.WriteToFile();

	clrscr();

	Board *boardGame = new Board();
	boardGame->readBoardFile();

	vector<string> gameWords = boardGame->getWords();
	vector<string> gameCoords = boardGame->getCoords();
	vector<char> gameOris = boardGame->getOris();

	for (int i = 0; i < gameWords.size(); i++) 
	{
		boardGame->addWord(gameWords[i], gameOris[i], gameCoords[i]);
		Sleep(500);
		clrscr();
		boardGame->showBoard();
	}

}