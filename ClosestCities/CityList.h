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

	const double kRadiusOfTheEarthInKilometers = 6371.00;

	vector<City> _cityList;

public:
	CityList();
	~CityList();

	void fillFromFile(string fileName);

	double getDistance(City one, City two);

	City getCity(int vectorIndex);

	void getClosestCities(string cityName);

	void getFarthestCities(string cityName);
};

