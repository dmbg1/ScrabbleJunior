#include "Board.h"
#include "InputManagement.h"

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
				if (i == 0)
					cout << "   ";
				else
					cout << " " << vChar << " ";

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
		if (i != 0)
			vChar++;
		cout << endl;
		hChar = 'a';
	}
}

vector<string> Board::readFile(int wordsnum)
{
	int number_of_lines = 109581;
	vector<string> words;

	// a vector to hold all the indices: 0 to number_of_lines
	vector<int> line_indices(number_of_lines);
	iota(begin(line_indices), end(line_indices), 0); // init line_indices

	// C++11 random library (should be preferred over rand()/srand())
	random_device r;
	seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() };
	mt19937 eng(seed);

	// shuffle the line_indices:
	shuffle(begin(line_indices), end(line_indices), eng);

	int number_of_lines_to_select = wordsnum;
	//assert(number_of_lines_to_select <= number_of_lines);

	string line;
	ifstream file("WORDS.TXT");

	int line_number = 0;

	cout << endl << "Selected words: " << endl;
	while (getline(file, line)) {
		for (int i = 0; i < number_of_lines_to_select; ++i) {
			if (line_number == line_indices[i]) {
				cout << line << endl;
				words.push_back(line);
			}
		}
		++line_number;
	}

	return words;
}

void Board::addWord(string word, char orientation)
{
	string key;
	while (1)
	{
		key = keyInput();
		if (key == "0")
			return;
		if (!isAddable(word, orientation, key)) {
			cout << endl << "Choose another Key" << endl;
			continue;
		}
		break;
	}
	if (orientation == 'H' || orientation == 'h') {
		for (int i = 0; i < word.size(); i++) {
			m[key] = word[i];
			key[1]++;
		}
	}
	else if (orientation == 'V' || orientation == 'v') {

		for (int i = 0; i < word.size(); i++) {
			m[key] = word[i];
			key[0]++;
		}
	}
}

bool Board::isAddable(string word, char orientation, string key) {
	if (orientation == 'V' || orientation == 'v') {
		if (key[0] + word.size() > 'A' + size) 
			return false;

		for (int i = 0; i < word.size(); i++) {
			if (m[key] == NULL) {
				if (i == 0) {
					key[0]--;
					if (m[key] != NULL)
						return false;
					key[0]++;
				}

				key[1]++;
				if (m[key] != NULL) 
					return false;
				key[1]--;

				key[1]--;
				if (m[key] != NULL) 
					return false;
				key[1]++;
			}
			else {
				if (m[key] != word[i])
					return false;

				key[0]++;
				if (m[key] != NULL)
					return false;
				key[0]--;
			}
			key[0]++;
		}
	}
	else if (orientation == 'H' || orientation == 'h') {
		if (key[1] + word.size() > 'a' + size)
			return false;

		for (int i = 0; i < word.size(); i++) {
			if (m[key] == NULL) {
				key[0]--;
				if (m[key] != NULL) {
					return false;
				}
				key[0]++;

				key[0]++;
				if (m[key] != NULL)
					return false;
				key[0]--;

				if (i == 0) {
					key[1]--;
					if (m[key] != NULL)
						return false;
					key[1]++;
				}
			}
			else {
				if (m[key] != word[i])
					return false;

				key[1]++;
				if (m[key] != NULL)
					return false;
				key[1]--;
			}
			key[1]++;
		}
	}
	return true;
}
