#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

#define BLACK 0
#define WHITE 15

void clrscr(void);

// Set text color & background
void setcolor(unsigned int color, unsigned int background_color);