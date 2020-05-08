#include "Board.h"

Board::Board(unsigned int s) {
	size = s;
}

unsigned int Board::getSize() const {
	return size;
}

map<string, char> Board::getM() const {
	return m;
}

void Board::showBoard() {
	char hChar = 'a', vChar = 'A';
	ostringstream aux;
	cout << endl;
	for (int i = 0; i < size + 1; i++) {
		for (int j = 0; j < size + 1; j++) {
			
			if (j == 0) {
				if(i==0)
					cout << "   ";
				else 
					cout << " " << vChar<< " ";
			
				continue;
			}
			if (i == 0)
				cout << hChar << " ";
			else {
				aux.str(string());
				aux << vChar << hChar;
				setcolor(BLACK, WHITE);
				cout << m[aux.str()];
	
				if (j == size)
					continue;
				else cout << " ";
			
			}

			hChar++;
		}
		setcolor(WHITE, BLACK);
		if(i != 0) 
			vChar++;
		cout << endl;
		hChar = 'a';
	}
}

void Board::addWord(string key, string word, char orientation)
{
	for (int i = 0; i < word.size(); i++) {
		if (orientation == 'H' || orientation == 'h') {
			m[key] = word[i];
			key[1] = key[1] + 1;
		}
		else if (orientation == 'V' || orientation == 'v') {
			m[key] = word[i];
			key[0] = key[0] + 1;
		}
	}
}
