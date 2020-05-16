#include <iostream>
#include "Player.h"
#include "InputManagement.h"

using namespace std;

int main() {
	int nPlayers;
	playerNumberInput(nPlayers);
	vector<Player> players;
	
	cout << nPlayers << endl;
	for (int i = 1; i <= nPlayers; i++)
		players.push_back(Player(i));


	return 0;
}