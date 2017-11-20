#include "City.h"


City::City()
{
	setCityName("");
	setCityCountry("");
	setCityCoordinates(0.0, 0.0);
}

City::City(string cityName, string cityCountry, double latitude, double longitude)
{
	setCityName(cityName);
	setCityCountry(cityCountry);
	setCityCoordinates(latitude, longitude);
}


City::~City()
{
}

string City::getCityName() {
	return _cityName;
}

void City::setCityName(string cityName) {
	_cityName = cityName;
}

string City::getCityCountry()
{
	return _cityCountry;
}

void City::setCityCountry(string cityCountry)
{
	_cityCountry = cityCountry;
}

Coordinate City::getCityCoordinates()
{
	return _cityCoordinates;
}

void City::setCityCoordinates(double latitude, double longitude)
{
	_cityCoordinates.setLatitude(latitude);
	_cityCoordinates.setLongitude(longitude);
}
