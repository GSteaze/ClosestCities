#include "Coordinate.h"



double Coordinate::doubleValidator(double value, double min, double max, string valueName)
{
	bool isValidInput = (value >= min) && (value <= max);

	while (!isValidInput) {
		cout << valueName << " must be between " << min << " and " << max << " : ";
		double userInput = 0;

		cin >> userInput;
		if (cin.fail() || userInput < min || userInput > max) {
			cout << "Please try again : ";
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
		}
		else if (userInput >= min && userInput <= max) {
			value = userInput;
			isValidInput = true;
		}
	}
	return value;
}

Coordinate::Coordinate()
{
	setLatitude(0.00);
	setLongitude(0.00);
}

Coordinate::Coordinate(double latitude, double longitude)
{
	setLatitude(latitude);
	setLongitude(longitude);
}


Coordinate::~Coordinate()
{
}


double Coordinate::getLatitude() {
	return _latitude;
}

void Coordinate::setLatitude(double latitude) {
	_latitude = doubleValidator(latitude, kLatitudeMin, kLatitudeMax, "Latitude");
}

double Coordinate::getLongitude() {
	return _longitude;
}

void Coordinate::setLongitude(double longitude) {
	_longitude = doubleValidator(longitude, kLongitudeMin, kLongitudeMax, "Longitude");
}