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

int readNumber(string msg)
{
	string line;
	int num = 0;
	bool error = false;

	do
	{
		cout << msg;
		getline(cin, line);

		error = any_of(line.begin(), line.end(), ::isalpha); //Ver se tem alguma letra

		if (error)
			cout << "Invalid Input. Can not have letters." << endl;

		if (!error && line == "") {
			error = true;
			cout << "Empty Input. " << endl;
		}

		if (!error) {
			for (auto x : line) {
				if (isspace(x)) {
					error = true;
					break;
				}
			}
			if (error)
				cout << "Invalid Input. Can not have spaces." << endl;
		}

		if (!error) {
			try {
				num = stoi(line);
			}
			catch (invalid_argument&) { //Ver se tem caracter especial
				error = true;
				cout << "Invalid Input. Can not have special characters." << endl;
			}
			catch (out_of_range&) { //Ver se o numero e demasiado grande
				error = true;
				cout << "Invalid Input. Number is to big." << endl;
			}
		}

		if (!error && line.size() != to_string(stoi(line)).size()) {
			for (auto x : line) {
				if (ispunct(x)) {
					error = true;
					break;
				}
			}
			if (error)
				cout << "Invalid Input. Can not have special characters." << endl;
		}

	} while (error);

	num = stoi(line);
	return num;
}


