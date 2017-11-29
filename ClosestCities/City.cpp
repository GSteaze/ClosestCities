#include "City.h"


City::City()
{
	setCityName("");
	setCityCountry("");
	setCityCoordinates(0.0, 0.0);
	setIndex(0);
	setDistanceFromCity(0.0);
}

City::City(string cityName, string cityCountry, double latitude, double longitude)
{
	setCityName(cityName);
	setCityCountry(cityCountry);
	setCityCoordinates(latitude, longitude);
}

City::City(string cityLine)
{
	string tempLine = cityLine;
	string token = "";
	string fieldsOfCity[4];
	int fieldNumber = 0;
	char delimiter = ',';
	int start = 0;
	int end = tempLine.find(delimiter);
	while (end != string::npos) {
		token = tempLine.substr(start, (end - start));
		fieldsOfCity[fieldNumber] = token;
		fieldNumber++;
		start = end + 1;
		end = tempLine.find(delimiter, start);
	}
	token = tempLine.substr(start, (end - start));
	fieldsOfCity[fieldNumber] = token;

	double cityLatitude = 0.0;
	double cityLongitude = 0.0;
	for (int index = 0; index < kNumberOfCityFields; index++) {
		switch (index) {
		case 0: setCityName(fieldsOfCity[index]);
			break;
		case 1: setCityCountry(fieldsOfCity[index]);
			break;
		case 2: string::size_type sz;
			cityLatitude = stod(fieldsOfCity[index], &sz);
			break;
		case 3: string::size_type sz2;
			cityLongitude = stod(fieldsOfCity[index], &sz2);
			setCityCoordinates(cityLatitude, cityLongitude);
			break;
		default: cout << "Invalid field detected" << endl;
		}
	}
}


City::~City()
{
}

string City::getCityName() {
	return _cityName;
}

string City::getLowerCaseCityName()
{
	string lowerCaseCityName = getCityName();
	for (int index = 0; index < lowerCaseCityName.size(); index++) {
		lowerCaseCityName[index] = tolower(lowerCaseCityName[index]);
	}
	return lowerCaseCityName;
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

int City::getIndex()
{
	return _index;
}

void City::setIndex(int index)
{
	_index = index;
}



double City::getDistanceFromCity()
{
	return _distanceFromCity;
}

void City::setDistanceFromCity(double distanceFromCity)
{
	_distanceFromCity = distanceFromCity;
}



