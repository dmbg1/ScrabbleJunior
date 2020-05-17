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

		cout << "Name of Board File (type 0 to exit program): " << endl;
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

vector<char> Board::getChars() const
{
	return chars;
}

vector<string> Board::getCoords() const
{
	return coords;
}

map<string, char> Board::getM() const
{
	return m;
}

vector<Player> Board::getPlayers() const
{
	return players;
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

void Board::showPlayersTiles() const
{
	for (Player player : players)
		player.showTiles();
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

				for (Player player : players) {	//checking if any player tiles are in the board (if so show color of the player's tile)
					if (player.getTilesPutInBoard()[aux.str()] != NULL) {
						if (player.getId() == 1)
							setcolor(BLUE, WHITE);
						else if (player.getId() == 2)
							setcolor(RED, WHITE);
						else if (player.getId() == 3)
							setcolor(GREEN, WHITE);
						else if (player.getId() == 4)
							setcolor(YELLOW, WHITE);
					}
				}

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

//Function checks if there's still at least 1 tile to be played
bool Board::playersHavePieces() const
{
	for (Player player : players)
		if (player.getTiles().size() != 0)
			return 1;
	return 0;
}

void Board::gameTurn(int playerId, Pool &p)
{
	string msg;
	int tile;
	string key;

	if (canPlay(players[playerId - 1])) {
		int j = 0;
		while (j < 2) {
			if (!canPlay(players[playerId - 1])) break;
			msg = "\nPlayer ";
			msg += to_string(playerId);
			if (j == 0) {
				msg += " turn. Select a number of a tile : ";
			}
			else {
				msg += " turn. Select another tile : ";
			}
			cin.ignore(1);
			tile = readNumber(msg);
			key = coordInput();

			if (key == "0") continue;

			char playerTile = players[playerId - 1].getTiles()[tile - 1];

			if (playerTile != m[key])
			{
				cout << endl << "Invalid play" << endl;
				continue;
			}
			else {
				int validPlay = 0;
				int i = 0;
				for (string coord : coords) {
					if (key == coord) {
						validPlay = 1;
						players[playerId - 1].addTilesInBoard(key, playerTile);
						if (oris[i] == 'H') {
							coords[i][1]++;
							while(players[playerId -1].getTilesPutInBoard()[coords[i]] != NULL)
								coords[i][1]++;
						}
						
						else if (oris[i] == 'V') {
							coords[i][0]++;
							while (players[playerId - 1].getTilesPutInBoard()[coords[i]] != NULL)
								coords[i][0]++;
						}
					
						if (m[coords[i]] == NULL)
							players[playerId - 1].incrementScore();
					}
					i++;
				}
				if (!validPlay)
				{
					cout << endl << "Invalid play" << endl;
					continue;
				}
			}
			j++;

			players[playerId - 1].eraseTile(tile - 1);
			Sleep(500);
			clrscr();
			showBoard();
			showPlayersTiles();
			cout << endl << "Tiles in pool: " << p.getPoolTiles().size() << endl;
			for (char c : p.getPoolTiles())
				cout << c << endl;
		}
		if (j == 2 && p.getPoolTiles().size() != 0) players[playerId - 1].drawTilesFromPool(p, 2);
		else if (j == 1 && p.getPoolTiles().size() != 0) players[playerId - 1].drawTilesFromPool(p, 1);
	}
	else {
		if (players[playerId - 1].getTiles.size() == 0)
			break;
		if (p.getPoolTiles().size() != 0)
			players[playerId - 1].reshufleTiles(p);
		else {
			cout << endl << "No available plays and no pool to pick up from!" << endl;
			Sleep(500);
		}
	}
}

bool Board::canPlay(Player p)
{
	for (string coord : coords) {
		for (char tile : players[p.getId() - 1].getTiles()) {
			if (tile == m[coord]) {
				return 1;
			}
		}
	}
	return 0;
}

void Board::setPlayers(vector<Player> p)
{
	players = p;
}


