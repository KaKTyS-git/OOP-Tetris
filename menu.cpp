#include "menu.h"

void Menu::printTitle() const
{
	cout << gameTitle;
}

void Menu::printHelp() const
{
	cout << help;
}

void Menu::printMenu() const
{
	cout << gameMenu;
}

int Menu::gamemodeWindow() const
{
	system("cls");
	int gmType;
	cout << gameMode;
	cin >> gmType;
	return gmType;
}
