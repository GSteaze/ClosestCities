#pragma once
#include <iostream>
#include <string>

using namespace std;

class Coordinate
{
private:
	
	const int kEndOfLine = 1024;
	const double kLatitudeMax = 90.00;
	const double kLatitudeMin = -90.00;
	const double kLongitudeMin = -180.00;
	const double kLongitudeMax = 180.00;

	double _latitude;
	double _longitude;

	double doubleValidator(double value, double min, double max, string valueName);

public:
	Coordinate();
	Coordinate(double latitude, double longitude);
	~Coordinate();

	double getLatitude();
	void setLatitude(double latitude);

	double getLongitude();
	void setLongitude(double longitude);
};

