#include "base.h"

void Base::print(int screen[ROWS_NUMBER][COLOMNS_NUMBER], int map[4][4], int xChanging, int yChanging, int score) const
{
	int i, j;
	int buff[ROWS_NUMBER][COLOMNS_NUMBER];

	for (i = 0; i < COLOMNS_NUMBER; i++)
		for (j = 0; j < ROWS_NUMBER; j++)
			buff[j][i] = screen[j][i];
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (map[j][i])
				buff[j + xChanging][i + yChanging] = 1;
	Operations::changeCursorPosition(0, 0);
	for (i = 0; i < COLOMNS_NUMBER; i++)
	{
		for (j = 0; j < ROWS_NUMBER; j++)
		{
			if (buff[j][i] == 0)
				cout << ' ';
			else
				cout << 'O';
		}
		cout << '\n';
	}
	for (int i = 0; i < ROWS_NUMBER; i++)
	{
		Operations::changeCursorPosition(i, COLOMNS_NUMBER);
		cout << '\xDB';
	}

	Operations::changeCursorPosition(COLOMNS_NUMBER + 2, 0);
	cout << "Your Score: " << score;
	for (int i = 0; i < COLOMNS_NUMBER + 1; i++)
	{
		Operations::changeCursorPosition(ROWS_NUMBER, i);
		cout << '\xDB';
	}
}

void Base::nextMap(Shapes x, int nextmap) const
{
	int i, j;
	Operations::changeCursorPosition(ROWS_NUMBER + 2, 2);
	cout << "Next: ";

	for (i = 0; i < 4; i++)
	{
		Operations::changeCursorPosition(ROWS_NUMBER + 2, i + 3);
		for (j = 0; j < 4; j++)
		{
			if (x.figures(nextmap, j, i) == 0)
				cout << ' ';
			else
				cout << 'O';
		}
	}
}
