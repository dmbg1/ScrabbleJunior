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