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
	int counter = 1;
	while (!fin.eof()) {
		getline(fin, cityLine);
		if (!cityLine.empty()) {
		City newCity = City(cityLine);
		newCity.setIndex(counter);
		counter++;
		_cityList.push_back(newCity);
		}
	}
	fin.close();
}

double CityList::getDistance(City one, City two)
{
	double distance = 0.0;
	Coordinate cityOneCoordinate = one.getCityCoordinates();
	Coordinate cityTwoCoordinate = two.getCityCoordinates();
	Coordinate differenceOfCoordinates = Coordinate();
	differenceOfCoordinates.setDifferenceLatitude(cityTwoCoordinate.getLatitude() - cityOneCoordinate.getLatitude());
	differenceOfCoordinates.setDifferenceLongitude(cityTwoCoordinate.getLongitude() - cityOneCoordinate.getLongitude());

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

vector<City> CityList::getClosestCitiesByCityName(string cityName, int numberOfCities)
{
	string lowerCaseCityName = cityName;
	for (int index = 0; index < lowerCaseCityName.size(); index++) {
		lowerCaseCityName[index] = tolower(lowerCaseCityName[index]);
	}

	string matchingCityName = "";
	string cityCountry = "";
	double cityLatitude = 0.0;
	double cityLongitude = 0.0;

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		if (lowerCaseCityName == (it->getLowerCaseCityName())) {
			matchingCityName = it->getCityName();
			cityCountry = it->getCityCountry();
			Coordinate cityCoordinates = it->getCityCoordinates();
			cityLatitude = cityCoordinates.getLatitude();
			cityLongitude = cityCoordinates.getLongitude();
		}
	}
	City selectedCity = City(matchingCityName, cityCountry, cityLatitude, cityLongitude);

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		it->setDistanceFromCity(getDistance(selectedCity, *it));
	}

	sort(_cityList.begin(), _cityList.end());

	vector<City> closestCities;
	int counter = 0;
	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++, counter++) {
		if (counter < numberOfCities) {
			closestCities.push_back(*it);
		}
	}

	return closestCities;
}

vector<City> CityList::getClosestCitiesByCityIndex(int cityIndex, int numberOfCities)
{

	string matchingCityName = "";
	string cityCountry = "";
	double cityLatitude = 0.0;
	double cityLongitude = 0.0;

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		if ( cityIndex == (it->getIndex())) {
			matchingCityName = it->getCityName();
			cityCountry = it->getCityCountry();
			Coordinate cityCoordinates = it->getCityCoordinates();
			cityLatitude = cityCoordinates.getLatitude();
			cityLongitude = cityCoordinates.getLongitude();
		}
	}
	City selectedCity = City(matchingCityName, cityCountry, cityLatitude, cityLongitude);

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		it->setDistanceFromCity(getDistance(selectedCity, *it));
	}

	sort(_cityList.begin(), _cityList.end());

	vector<City> closestCities;
	int counter = 0;
	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++, counter++) {
		if (counter < numberOfCities) {
			closestCities.push_back(*it);
		}
	}

	return closestCities;

}

vector<City> CityList::getFarthestCitiesByCityName(string cityName, int numberOfCities)
{
	string lowerCaseCityName = cityName;
	for (int index = 0; index < lowerCaseCityName.size(); index++) {
		lowerCaseCityName[index] = tolower(lowerCaseCityName[index]);
	}

	string matchingCityName = "";
	string cityCountry = "";
	double cityLatitude = 0.0;
	double cityLongitude = 0.0;

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		if (lowerCaseCityName == (it->getLowerCaseCityName())) {
			matchingCityName = it->getCityName();
			cityCountry = it->getCityCountry();
			Coordinate cityCoordinates = it->getCityCoordinates();
			cityLatitude = cityCoordinates.getLatitude();
			cityLongitude = cityCoordinates.getLongitude();
		}
	}
	City selectedCity = City(matchingCityName, cityCountry, cityLatitude, cityLongitude);

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		it->setDistanceFromCity(getDistance(selectedCity, *it));
	}

	sort(_cityList.begin(), _cityList.end());

	vector<City> closestCities;
	int counter = 0;
	for (vector<City>::reverse_iterator it = _cityList.rbegin(); it != _cityList.rend(); it++, counter++) {
		if (counter < numberOfCities) {
			closestCities.push_back(*it);
		}
	}

	return closestCities;
}

vector<City> CityList::getFarthestCitiesByCityIndex(int cityIndex, int numberOfCities)
{
	string matchingCityName = "";
	string cityCountry = "";
	double cityLatitude = 0.0;
	double cityLongitude = 0.0;

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		if (cityIndex == (it->getIndex())) {
			matchingCityName = it->getCityName();
			cityCountry = it->getCityCountry();
			Coordinate cityCoordinates = it->getCityCoordinates();
			cityLatitude = cityCoordinates.getLatitude();
			cityLongitude = cityCoordinates.getLongitude();
		}
	}
	City selectedCity = City(matchingCityName, cityCountry, cityLatitude, cityLongitude);

	for (vector<City>::iterator it = _cityList.begin(); it != _cityList.end(); it++) {
		it->setDistanceFromCity(getDistance(selectedCity, *it));
	}

	sort(_cityList.begin(), _cityList.end());

	vector<City> closestCities;
	int counter = 0;
	for (vector<City>::reverse_iterator it = _cityList.rbegin(); it != _cityList.rend(); it++, counter++) {
		if (counter < numberOfCities) {
			closestCities.push_back(*it);
		}
	}

	return closestCities;
}
