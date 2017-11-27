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
	const int kEndOfLine = 1024;

	vector<City> _cityList;

public:
	CityList();
	~CityList();

	void fillFromFile(string fileName);

	double getDistance(City one, City two);

	City getCity(int vectorIndex);

	vector<City> getClosestCitiesByCityName(string cityName, int numberOfCities);
	vector<City> getClosestCitiesByCityIndex(int cityIndex, int numberOfCities);

	vector<City> getFarthestCitiesByCityName(string cityName, int numberOfCities);
	vector<City> getFarthestCitiesByCityIndex(int cityIndex, int numberOfCities);
};

