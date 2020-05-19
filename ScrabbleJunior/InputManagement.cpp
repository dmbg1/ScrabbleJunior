#include "InputManagement.h"

void playerNumberInput(int& nPlayers)
{
	while(1) {
		cout << endl << "How many players ? ";
		cin >> nPlayers;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		if (nPlayers > 4 || nPlayers < 2) {
			cout << "Invalid number of players (2 to 4 players game)" << endl;
			continue;
		}
		break;
	}
}

string coordInput()
{
	string key;

	while (1) {
		cout << endl << "Select the coordinate to place the tile in (0 to go back to previous input): " << endl;
		cin >> key;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		if (key == "0") break;

		if (key.size() != 2) {	//key must be size 2
			cout << "Incorrect size of coord" << endl;
			continue;
		}
		if (islower(key[0])) {	//key 1 must be uppercase
			cout << "Firt character must be uppercase" << endl;
			continue;
		}
		if (isupper(key[1])) {	//key 2 must be lowercase
			cout << "Second character must be lowercase" << endl;
			continue;
		}
		if (key[0] < 'A' || key[0] >'Z' || key[1] < 'a' || key[1] > 'z') {
			cout << "Characters must be members of the alphabet" << endl;
			continue;
		}
		break;
	}
	return key;
}

int tileInput(const string msg, const int maxTile)
{
	int num;

	while (1)
	{
		cout << msg;
		cin >> num;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		
		if (num > maxTile || num < 1) {
			cout << "That tile doesn't exist" << endl;
			continue;
		}

		break;
	}

	return num;
}


