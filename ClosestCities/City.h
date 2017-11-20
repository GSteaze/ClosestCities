#pragma once
#include <string>
#include "Coordinate.h"

using namespace std;

class City
{
private:
	string _cityName;
	string _cityCountry;
	Coordinate _cityCoordinates;

public:
	City();
	City(string cityName, string cityCountry, double latitude, double longitude);
	~City();

	string getCityName();
	void setCityName(string cityName);

	string getCityCountry();
	void setCityCountry(string cityCountry);

	Coordinate getCityCoordinates();
	void setCityCoordinates(double latitude, double longitude);


};

