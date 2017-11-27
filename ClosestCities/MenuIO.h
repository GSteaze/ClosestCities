#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "City.h"
#include "CityList.h"

using namespace std;

class MenuIO
{
private:
	
	const int kEndOfLine = 1024;
	const int kMenuOptionMinimum = 1;
	const int kMenuOptionMaximum = 3;
	const int kMaximumIndexNumber = 10000;
	const int kNumberOfCityResults = 5;
	void displayWelcomeMessage();

	CityList cities;

public:
	MenuIO();
	~MenuIO();

	void displayMenu();

	int userSelectsIndexOrCityName();

	int intValidator(int min, int max);
	string stringValidator(string desiredField);
};

