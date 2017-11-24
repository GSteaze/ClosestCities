#pragma once
#include <string>
#include "Coordinate.h"

using namespace std;

class City
{
private:

	const int kNumberOfCityFields = 4;

	string _cityName;
	string _cityCountry;
	Coordinate _cityCoordinates;

public:
	City();
	City(string cityName, string cityCountry, double latitude, double longitude);
	City(string cityLine);
	~City();

	string getCityName();
	void setCityName(string cityName);

	string getCityCountry();
	void setCityCountry(string cityCountry);

	Coordinate getCityCoordinates();
	void setCityCoordinates(double latitude, double longitude);

};

