#pragma once
#include <iostream>

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
		if (size < 11) {	//Avoiding too low sized boards (with less than 101 letter positions)
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