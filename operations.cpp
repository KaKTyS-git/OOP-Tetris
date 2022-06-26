#include "operations.h"

int Operations::random() const
{
	return (rand() % FIGURES_NUMBER);
}

int Operations::getKey() const
{
	int key;
	if (_kbhit()) //Проверка на нажатие любой клавиши 
	{
		if ((key = _getch()) == 224) //Дополнительный код клавиш стрелок, который необходимо пропустить
			key = _getch();
		return key;
	}
	return 0;
}

void Operations::clear(int screen[ROWS_NUMBER][COLOMNS_NUMBER]) const
{
	int i, j;
	for (i = 0; i < COLOMNS_NUMBER; i++)
		for (j = 0; j < ROWS_NUMBER; j++)
			screen[j][i] = 0;
}

void Operations::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Operations::changeCursorPosition(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
