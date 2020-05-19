#pragma once
#include <iostream>

using namespace std;

// Treats number of players input 
void playerNumberInput(int& nPlayers); 

// Treats coordinate inputs
string coordInput();

// Treats tile number input
int tileInput(const string msg, const int maxTile);