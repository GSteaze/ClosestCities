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


	bool operator< (City &rhs) {
		return _distanceFromCity < rhs.getDistanceFromCity();
	}
	bool operator==(City &rhs) {
		return _distanceFromCity == rhs.getDistanceFromCity();
	}

	City& City::operator=(City &rhs) {
		if (this != &rhs) {
			this->_cityName = rhs._cityName;
			this->_cityCountry = rhs._cityCountry;
			double latitude = rhs._cityCoordinates.getLatitude();
			double longitude = rhs._cityCoordinates.getLongitude();
			this->setCityCoordinates(latitude, longitude);
			this->_distanceFromCity = rhs._distanceFromCity;
		}
		return *this;
	}
};