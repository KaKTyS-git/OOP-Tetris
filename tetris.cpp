#include "tetris.h"

bool Tetris::drawNewPosition(int x, int y) const //Проверка на возможность отрисовать новую фигуру
{
	int i, j;
	if (x < 0)
		return false;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (map[j][i])
			{
				if ((j + x >= ROWS_NUMBER) || (i + y >= COLOMNS_NUMBER))
					return false;
				if (screen[j + x][i + y])
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Tetris::moveDownStep(int xChanging, int yChanging) 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (map[j][i])
				screen[xChanging + j][yChanging + i] = 1;
		}
	}
}

void Tetris::moveDownFast(int screen[ROWS_NUMBER][COLOMNS_NUMBER]) 
{
	for (; drawNewPosition(xChanging, yChanging + 1); yChanging++);
	{
		moveDownStep(xChanging, yChanging);
	}
}

void Tetris::rotateMap()  //Поворот по часовой стрелке
{
	int tempMap[4][4];
	int i, j, xRotate = 4, yRotate = 4;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			tempMap[j][i] = map[j][i];
			if (map[j][i])
			{
				if (i < xRotate)
					xRotate = i;
				if ((-j + 3)< yRotate)
					yRotate = (-j + 3);
			}
			map[j][i] = 0;
		}

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (tempMap[(-i + 3)][j])
				map[j - xRotate][i - yRotate] = 1;

	if (!drawNewPosition(xChanging, yChanging))
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				map[j][i] = tempMap[j][i];
}

void Tetris::deleteLine(int screen[ROWS_NUMBER][COLOMNS_NUMBER])
{
	int i, j, k;
	bool flag;
	Base field;
	for (i = COLOMNS_NUMBER - 1; i >= 0; i--)
	{
		flag = true;
		for (j = 0, flag = true; j < ROWS_NUMBER; j++)
		{
			if (!screen[j][i])
				flag = false;
		}
		if (flag)
		{
			Operations::changeCursorPosition(0, i);
			for (k = 0; k < ROWS_NUMBER; k++)
			{
				cout << '_';
				Sleep(20);
			}

			score += (((i * (-1)) + COLOMNS_NUMBER) * 10);

			for (k = i; k > 0; k--)
			{
				for (j = 0; j < ROWS_NUMBER; j++)
				{
					screen[j][k] = screen[j][k - 1];
				}
			}
			i++;
			field.print(screen, map, xChanging, yChanging, score);
		}
	}
}

void Tetris::createMap()
{
	Operations operations;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			map[j][i] = x.figures(nextMap, i, j);
	yChanging = 0;
	xChanging = 8;
	Base field;
	nextMap = operations.random();
	field.nextMap(x, nextMap);
}

void Tetris::startGame(int gameMode) //Обработка кнопок и определение скорости падения
{
	int i, symbolCode;
	Operations::showConsoleCursor(false);
	system("cls");
	Operations operations;
	Base field;
	time_t time;
	xChanging = 8;
	yChanging = 0;
	score = 0;
	nextMap = operations.random();
	createMap();
	time = clock();
	while (true)
	{
		symbolCode = operations.getKey();
		switch (symbolCode)
		{
		case 32: //Пробел
			rotateMap();
			break;
		case 80: //Стрелка вниз
			moveDownFast(screen);
			field.print(screen, map, xChanging, yChanging, score);
			deleteLine(screen);
			createMap();
			break;
		case 75: //Стрелка влево
			if (drawNewPosition(xChanging - 1, yChanging))
				xChanging--;
			break;
		case 77: //Стрелка вправо
			if (drawNewPosition(xChanging + 1, yChanging))
				xChanging++;
			break;
		case 'p': //Кнопка паузы 'P'
			_getch();
			break;
		case 27: //Выход "Esc"
			return;
		}
		if (gameMode) //GameMode
		{
			int speed;
			if (gameMode == 1)
				speed = 700;
			else if (gameMode == 2)
				speed = 500;
			else if (gameMode == 3)
				speed = 300;
			else if (gameMode == 4)
				speed = 200;
			if ((clock() - time) > speed)
			{
				time = clock();

				if (!(drawNewPosition(xChanging, yChanging + 1)))
				{
					moveDownStep(xChanging, yChanging);
					createMap();
					deleteLine(screen);
				}
				else yChanging++;
			}
		}
		field.print(screen, map, xChanging, yChanging, score);

		for (i = 0; i < 16; i++)
		{
			if (screen[i][0])
			{
				system("cls");
				Operations::changeCursorPosition(2, 8);
				printf("Game Over!");
				return;
			}
		}
	}
}

void Tetris::gameMenu() //Обработка выборов в главном меню
{
	Operations operations;
	Menu phrase, gameMode;
	int symbolCode, symbol;

	system("cls");
	phrase.printTitle();
	phrase.printMenu();
	while (true)
	{
		system("color 70");
		symbol = _getch();
		switch (symbol)
		{
		case '1':
		case '2':
		case '3':
		case '4':
			symbolCode = symbol - 48;
		case 13:
			switch (symbolCode)
			{
			case 1:
				operations.clear(screen);
				startGame(gameMode.gamemodeWindow());
				Operations::changeCursorPosition(0, 20);
				cout << "Press ESC to return main menu..\n \a";
				while (_getch() != 27);
				break;
			case 2:
				startGame(gameMode.gamemodeWindow());
				Operations::changeCursorPosition(0, 20);
				cout << "Press ESC to return main menu..\n \a";
				while (_getch() != 27);
				break;
			case 3:
				system("cls");
				phrase.printTitle();
				phrase.printHelp();
				_getch();
				if (_kbhit())
					_getch();
				break;

			case 4: return;
			}
			system("cls");
			phrase.printTitle();
			phrase.printMenu();
			symbolCode = 1;
			break;
		case 80:
			if (symbolCode < 4) 
				symbolCode++;
			break;
		case 27:
			return;
		}
	}
}

void Tetris::gameTitle()
{
	Menu title;
	title.printTitle();
	_getch();
	printf("Press any key to continue...");
	Tetris::gameMenu();
	system("color 58");
	_getch();
	if (_kbhit())
		_getch();
}
