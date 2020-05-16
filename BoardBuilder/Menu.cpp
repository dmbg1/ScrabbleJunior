#include "Menu.h"

using namespace std;

int mainMenu() {
    cout << "__________________________________________________\n" << endl;
    cout << setw(23) << right << "Scrabble Junior" << endl;
    cout << "__________________________________________________\n" << endl;
    cout << "1 - Build New Board\n";
    cout << "\n0 - Exit\n";
    cout << "__________________________________________________\n" << endl;
    return ieMenu(1);
}