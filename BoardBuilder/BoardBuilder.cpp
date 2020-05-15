#include "Board.h"
#include "InputManagement.h"
#include "gui.h"
#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
	
	int op;

	do {
		clrscr();
		op = mainMenu();
		if (op == 0)
			break;
		if (op == 1) {

			int size; //Largura e comprimento
			string key;
			char ori;

			Sleep(500);
			clrscr();

			cout << "__________________________________________________\n" << endl;
			cout << setw(23) << right << "Board Builder" << endl;
			cout << "__________________________________________________\n" << endl;

			sizeInput(size);
			int num = numWords();

			Board board = Board();

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
		}

		if (op == 2) {

			Board* boardGame = new Board();
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
			int a;
			while (1) {
				cout << endl << "0 to return" << endl;
				cin >> a;
				if (a != 0) continue;
				break;
			}
		}
	} while (op != 0);
}