#include "Board.h"
#include "InputManagement.h"
#include "gui.h"
#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
	Board board;
	int op;
	int size; //Largura e comprimento

	do {
		clrscr();
		op = mainMenu();
		if (op == 0)
			break;
		if (op == 1) {

			string key;
			char ori;

			Sleep(500);
			clrscr();

			cout << "__________________________________________________\n" << endl;
			cout << setw(23) << right << "Board Builder" << endl;
			cout << "__________________________________________________\n" << endl;

			sizeInput(size);
			int num = numWords();

			board = Board(size);

			Sleep(500);
			clrscr();

			board.showBoard();
			board.readFile(num);

			vector<string> words = board.getWords();

			for (int i = 0; i < words.size(); i++)	
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

			board.readBoardFile();

			vector<string> gameWords = board.getWords();
			vector<string> gameCoords = board.getCoords();
			vector<char> gameOris = board.getOris();

			for (int i = 0; i < gameWords.size(); i++)
			{
				Sleep(500);
				clrscr();
				board.showBoard();
				board.addWord(gameWords[i], gameOris[i], gameCoords[i]);
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