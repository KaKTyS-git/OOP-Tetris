#pragma once

#include "shapes.h"
#include "menu.h"
#include "base.h"
#include "operations.h"
#include <time.h>

class Tetris {
private:
	Shapes x;
	int screen[ROWS_NUMBER][COLOMNS_NUMBER];
	int map[4][4];
	int xChanging, yChanging;
	int score, nextMap;

public:
	bool drawNewPosition(int x, int y) const;
	void moveDownStep(int xChanging, int yChanging);
	void moveDownFast(int screen[ROWS_NUMBER][COLOMNS_NUMBER]);
	void rotateMap(); 
	void deleteLine(int screen[ROWS_NUMBER][COLOMNS_NUMBER]);
	void createMap();
	void startGame(int gameMode);

public:
	void gameMenu();
	void gameTitle();
};
