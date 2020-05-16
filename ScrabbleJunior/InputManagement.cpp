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

