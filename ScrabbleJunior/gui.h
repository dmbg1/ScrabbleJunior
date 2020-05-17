#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE 15

void clrscr(void);

void setcolor(unsigned int color);

// Set text color & background
void setcolor(unsigned int color, unsigned int background_color);