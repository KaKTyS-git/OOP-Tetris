#pragma once

#include "operations.h"
#include "title.h"

class Menu : private Title
{
public:
	void printTitle() const;
	void printHelp() const;
	void printMenu() const;
	int gamemodeWindow() const;
};