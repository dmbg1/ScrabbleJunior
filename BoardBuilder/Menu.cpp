#include "Menu.h"

using namespace std;

int mainMenu() {
    cout << "__________________________________________________\n" << endl;
    cout << setw(35) << right << "Scrabble Junior Board Builder" << endl;
    cout << "__________________________________________________\n" << endl;
    cout << "1 - Build New Board\n";
    cout << "\n0 - Exit\n";
    cout << "__________________________________________________\n" << endl;
    return ieMenu(1);
}