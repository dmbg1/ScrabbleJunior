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

		if (!isdigit(line[0]))
		{
			cout << "The file is corrupted1" << endl;
			continue;
		}
		a = line[0];
		b = line[1];
		ssize = a + b;

		size = stoi(ssize);

		while (getline(file, line)) {

			if (!isupper(line[0]) || !islower(line[1]) || !isspace(line[2]) || !isalpha(line[3]) || !isspace(line[4]) || !isalpha(line[5]))
			{
				cout << "The file is corrupted2" << endl;
				continue;
			}

			a = line[0];
			b = line[1];
			coord = a + b;
			ori = line[3];
			word = "";

			for (string::iterator it = line.begin() + 5; it != line.end(); it++)
				word = word + *it;

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

void Board::addPlayers(const int n, Pool &pool)
{
	for (int i = 1; i <= n; i++) {
		players.push_back(Player(i));
		players[i - 1].drawTilesFromPool(pool, 7);
	}
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

				for (Player player : players) {	// Cycle to see if any player tiles are in the board (if so show color of the player's tile)

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


bool Board::playersHavePieces() const
{
	for (Player player : players)
		if (player.getTiles().size() != 0)
			return 1;

	return 0;
}


void Board::gameTurn(int playerId, Pool& p)
{

	if (players[playerId - 1].getTiles().size() == 0) // Player has no more pieces 
		return;

	string msg;	// To save the msg that asks for the player tile input
	int tile;	// Saves tile "identifier" integer the player chooses for the tile
	string coordinate;	// Saves coordinate where the player wants to put the tile on

	if (canPlay(players[playerId - 1])) { // Player can make a play

		int j = 0;
		while (j < 2) {	

			if (!canPlay(players[playerId - 1]))  // If a player can't play no more tiles break cycle
				break;

			msg = "\nPlayer ";
			msg += to_string(playerId);
			if (j == 0) 
				msg += " turn. Select a number of a tile : ";
			else 
				msg += " turn. Select another tile : ";

			tile = tileInput(msg, players[playerId - 1].getTiles().size());

			coordinate = coordInput();

			if (coordinate == "0") // Backtrack to the previous input
				continue;

			char playerTile = players[playerId - 1].getTiles()[tile - 1];

			if (playerTile != m[coordinate])
			{
				cout << "Invalid play" << endl;
				continue;
			}
			else {
				int validPlay = 0; //to check if the player's move is valid
				int i = 0;

				// Cycle to check all the available coordinates and place the tile the player chose if that is the case
				for (string coord : coords) {

					if (coordinate == coord) {	// Available coordinate
						validPlay = 1;

						addTileInBoard(coordinate, playerTile);
						players[playerId - 1].addTileInBoard(coordinate, playerTile);

						if (oris[i] == 'H') {
							coords[i][1]++;

							//incrementing the coordinate horizontally until the next empty/available spot
							while (tilesInBoard[coords[i]] != NULL)	
								coords[i][1]++;
						}
						else if (oris[i] == 'V') {
							coords[i][0]++;

							//incrementing the coordinate vertically until the next empty/available spot
							while (tilesInBoard[coords[i]] != NULL)
								coords[i][0]++;
						}

						if (m[coords[i]] == NULL)
							players[playerId - 1].incrementScore();
					}

					i++;
				}

				if (!validPlay)	// Player chose an invalid coordinate
				{
					cout << "Invalid play" << endl;
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
		}

		// player placed the 2 tiles so he picks up another 2 or 1 (depending on the disponibility of the pool from the non empty pool:
		if (j == 2 && p.getPoolTiles().size() != 0)
			players[playerId - 1].drawTilesFromPool(p, 2);
		// Player placed only 1 piece and has no more available plays so he picks 1 piece from non empty pool:
		else if (j == 1 && p.getPoolTiles().size() != 0) {
			players[playerId - 1].drawTilesFromPool(p, 1);
			cout << "No more playable pieces " << endl;
		}
		// Player placed only 1 piece and has no more available plays and, since the pool is empty he doesn't pick pieces from it and skips turn:
		else if (j == 1 && p.getPoolTiles().size() == 0)
			cout << "No more playable pieces " << endl;

	}
	else {

		if (p.getPoolTiles().size() != 0)	// No available plays and pool is not empty so reshufle pieces 
		{
			cout << endl << "Player " << playerId << " has no possible plays.";
			players[playerId - 1].reshufleTiles(p);
		}
		else {	//  No available plays and pool is empty so skip turn
			cout << endl << "No available plays and no tiles in pool" << endl;
			Sleep(500);
		}
	}

	Sleep(500);
	clrscr();
	showBoard();
	showPlayersTiles();
	cout << endl << "Tiles in pool: " << p.getPoolTiles().size() << endl;
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

void Board::addTileInBoard(const string coord, const char tile)
{
	tilesInBoard[coord] = tile;
}

