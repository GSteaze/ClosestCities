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
	int _index;
	double _distanceFromCity;

public:
	City();
	City(string cityName, string cityCountry, double latitude, double longitude);
	City(string cityLine);
	~City();

	string getCityName();
	string getLowerCaseCityName();
	void setCityName(string cityName);

	string getCityCountry();
	void setCityCountry(string cityCountry);

	Coordinate getCityCoordinates();
	void setCityCoordinates(double latitude, double longitude);

	int getIndex();
	void setIndex(int index);

	double getDistanceFromCity();
	void setDistanceFromCity(double distanceFromCity);

	bool operator< (City &other);
};