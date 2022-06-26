#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>

#define ROWS_NUMBER 16
#define COLOMNS_NUMBER 20
#define FIGURES_NUMBER 8

using namespace std;

class Operations {
public:
	int random() const;
	int getKey() const;
	void clear(int screen[ROWS_NUMBER][COLOMNS_NUMBER]) const;
	static void showConsoleCursor(bool showFlag);
	static void changeCursorPosition(int xpos, int ypos);
};