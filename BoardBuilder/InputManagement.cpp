#pragma once
#include "InputManagement.h"

using namespace std;

void sizeInput(int& size) {
	while (1) {
		cout << endl << "Board size (just one value because width=length) ? ";
		cin >> size;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		if (size > 20) {
			cout << "Max board size = 20" << endl;
			continue;
		}
		if (size < 10) {	//Avoiding too low sized boards 
			cout << "Board size too low" << endl;
			continue;
		}
		break;
	}
}

int numWords()
{

	int num;

	while (1) {
		cout << endl << "Select a Number of words ";
		cin >> num;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		if (num < 5) {	//Avoiding few words
			cout << "Number of words too low" << endl;
			continue;
		}
		break;
	}
	return num;
}

string keyInput()
{
	string key;

	while (1) {
		cout << endl << "Select a Key (0 to skip word): ";
		cin >> key;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		if (key == "0") break;

		if (key.size() != 2) {	//key must be size 2
			cout << "Incorrect size of key" << endl;
			continue;
		}
		if (islower(key[0])) {	//key 1 must be uppercase
			cout << "Key 1 must be uppercase" << endl;
			continue;
		}
		if (isupper(key[1])) {	//key 2 must be lowercase
			cout << "Key 2 must be lowercase" << endl;
			continue;
		}
		if (key[0] < 'A' || key[0] >'Z' || key[1] < 'a' || key[1] > 'z' ) {
			cout << "Keys must be members of the alphabet" << endl;
			continue;
		}
		break;
	}
	return key;
}

char orientationInput()
{
	char ori;

	while (1) {
		cout << endl << "Input V or H to choose orientation (0 to skip word)" << endl;
		cin >> ori;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		
		if (ori == '0') break;

		if (ori != 'V' && ori != 'H' && ori != 'v' && ori != 'h') {	//must be V/H/v/h
			cout << "Input must be V or v or H or h" << endl;
			continue;
		}
		break;
	}
	return ori;
}

int readNumber(string msg) {
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

int ieMenu(int maxOption) {
	int op;

	do {
		op = readNumber("Choose an option (number): ");
		if (op > maxOption || op < 0)
			cout << "Invalid Input. Invalid option." << endl;
	} while (op > maxOption || op < 0);

	return op;
}