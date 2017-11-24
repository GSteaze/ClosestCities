#include "CityList.h"



CityList::CityList()
{
}


CityList::~CityList()
{
}

void CityList::fillFromFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	string cityLine = "";
	getline(fin, cityLine);
	while (!fin.eof()) {
		getline(fin, cityLine);
		City newCity = City(cityLine);
		_cityList.push_back(newCity);
	}
	fin.close();
}

double CityList::getDistance(City one, City two)
{
	double distance = 0.0;
	Coordinate cityOneCoordinate = one.getCityCoordinates();
	Coordinate cityTwoCoordinate = two.getCityCoordinates();
	Coordinate differenceOfCoordinates = Coordinate(
		(cityTwoCoordinate.getLatitude() - cityOneCoordinate.getLatitude()), 
		(cityTwoCoordinate.getLongitude() - cityOneCoordinate.getLongitude())
	);

	
	double latOneRadians = cityOneCoordinate.getLatitudeRadians();
	double latTwoRadians = cityTwoCoordinate.getLatitudeRadians();
	double differenceLatRadians = differenceOfCoordinates.getLatitudeRadians();
	double differenceLongRadians = differenceOfCoordinates.getLongitudeRadians();

	double a = sin(differenceLatRadians / 2) * sin(differenceLatRadians / 2) +
		cos(latOneRadians) * cos(latTwoRadians) *
		sin(differenceLongRadians / 2) * sin(differenceLongRadians / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));

	double d = kRadiusOfTheEarthInKilometers * c;
	distance = d;

	return distance;
}

City CityList::getCity(int vectorIndex)
{
	return _cityList[vectorIndex];
}

void CityList::getClosestCities(string cityName)
{
	
	string matchingCityName = "";
	string cityCountry = "";
	double cityLatitude = 0.0;
	double cityLongitude = 0.0;

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		if (cityName == (it->getCityName)) {
			matchingCityName = it->getCityName;
			cityCountry = it->getCityCountry;
			Coordinate cityCoordinates = it->getCityCoordinates;
			cityLatitude = cityCoordinates.getLatitude();
			cityLongitude = cityCoordinates.getLongitude();
		}
	}
	City selectedCity = City(matchingCityName, cityCountry, cityLatitude, cityLongitude);

	vector<City> closestCities;

	//Need to write code to add and sort cities by distance

}
