#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "City.h"
#include "Coordinate.h"

using namespace std;

class CityList
{
private:

	const double kRadiusOfTheEarthInMeters = 6371000.00;

	vector<City> _cityList;

public:
	CityList();
	~CityList();

	void fillFromFile(string fileName);

	double getDistance(City one, City two);
};

