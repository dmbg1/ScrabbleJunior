#include "Board.h"

void Board::readBoardFile() {

	string filename;
	string line;
	string coord;
	string ssize;
	int siz;
	char ori;
	string word;
	string a;
	string b;

	while (1) {

		cout << endl << "Name of Board File (type 0 to exit program): " << endl;
		cin >> filename;

		if (filename == "0") exit(0);
		ifstream file(filename);

		if (!file)
		{
			cout << "The file doesn't exist" << endl;
			continue;
		}

		getline(file, line);

		if (!isdigit(line[0]) || !isdigit(line[1]))
		{
			cout << "The file is corrupted" << endl;
			continue;
		}
		a = line[0];
		b = line[1];
		ssize = a + b;

		size = stoi(ssize);

		while (getline(file, line)) {

			if (!isupper(line[0]) || !islower(line[1]) || !isspace(line[2]) || !isalpha(line[3]) || !isspace(line[4]) || !isalpha(line[5]))
			{
				cout << "The file is corrupted" << endl;
				continue;
			}

			a = line[0];
			b = line[1];
			coord = a + b;
			ori = line[3];
			word = "";
			for (string::iterator it = line.begin() + 5; it != line.end(); it++) {

				word = word + *it;
			}

			coords.push_back(coord);
			oris.push_back(ori);
			words.push_back(word);
		}
		file.close();
		mapBoard(coords);
		break;
	}
}

vector<char> Board::getChars()
{
	return chars;
}

vector<string> Board::getCoords()
{
	return coords;
}

map<string, char> Board::getM()
{
	return m;
}

void Board::mapBoard(vector<string> keys)
{
	for (int i = 0; i < words.size(); i++) {
		if (oris[i] == 'H') {
			for (int j = 0; j < words[i].size(); j++) {
				if (m[keys[i]] == NULL) {
					m[keys[i]] = toupper(words[i][j]);
					chars.push_back(m[keys[i]]);
				}
				keys[i][1]++;
			}
			keys[i][1] = keys[i][1] - words[i].size();
		}
		else if (oris[i] == 'V') {

			for (int j = 0; j < words[i].size(); j++) {
				if (m[keys[i]] == NULL) {
					m[keys[i]] = toupper(words[i][j]);
					chars.push_back(m[keys[i]]);
				}
				keys[i][0]++;
			}
			keys[i][0] = keys[i][0] - words[i].size();
		}
	}
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
