#pragma once
#include <iostream>
#include <string>

using namespace std;

class Coordinate
{
private:
	
	const int kEndOfLine = 1024;
	const double kPi = 3.1415927;
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
	void setDifferenceLatitude(double differenceLatitude);

	double getLongitude();
	void setLongitude(double longitude);
	void setDifferenceLongitude(double differenceLongitude);

	double getLatitudeRadians();

	double getLongitudeRadians();

	double toRadians(double degrees);
};

