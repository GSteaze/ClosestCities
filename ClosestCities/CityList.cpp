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

	double d = kRadiusOfTheEarthInMeters * c;

	return distance;
}
