#pragma once
#include <string>
#include <iostream>
#include "City.h"

using namespace std;

class MenuIO
{
private:

	const int kEndOfLine = 1024;
	const int kMenuOptionMinimum = 1;
	const int kMenuOptionMaximum = 3;
	void displayWelcomeMessage();

public:
	MenuIO();
	~MenuIO();

	void displayMenu();

	int intValidator(int min, int max);
	string stringValidator(string desiredField);
};

