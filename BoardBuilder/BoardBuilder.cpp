#include "Board.h"
#include "InputManagement.h"
#include "gui.h"
#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
	int op;
	int size; //Largura e comprimento

	do {
		clrscr();
		op = mainMenu();
		if (op == 0)
			break;
		if (op == 1) {

			string key;
			char ori = '0';

			Sleep(500);
			clrscr();

			cout << "__________________________________________________\n" << endl;
			cout << setw(23) << right << "Board Builder" << endl;
			cout << "__________________________________________________\n" << endl;

			sizeInput(size);
			int num = numWords();

			Board board = Board(size);

			Sleep(500);
			clrscr();

			board.showBoard();
			board.readFile(num);

			vector<string> words = board.getWords();

			for (int i = 0; i < words.size(); i++)
			{
				cout << endl << words[i] << ":";

				if ((ori = orientationInput()) == '0') {
					cout << endl << "Word discarded" << endl;
					continue;
				}
				if ((key = keyInput()) == "0") {
					cout << endl << "Word discarded" << endl;
					continue;
				}

				board.addWord(words[i], ori, key);
				Sleep(500);
				clrscr();
				board.showBoard();
			}

			if (key == "0" || ori == '0') {
				Sleep(500);
				clrscr();
			}

			board.createBoardFile();

			clrscr();
		}
	} while (op != 0);

	return 0;
}