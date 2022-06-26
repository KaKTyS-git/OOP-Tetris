#pragma once

#include "operations.h"
#include "shapes.h"

//Отрисовка процесса игры
class Base { 
public:
	void print(int screen[ROWS_NUMBER][COLOMNS_NUMBER], int map[4][4], int px, int py, int score) const;
	void nextMap(Shapes x, int nextmap) const;
};