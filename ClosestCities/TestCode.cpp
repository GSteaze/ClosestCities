#include "TestCode.h"



TestCode::TestCode()
{
}


TestCode::~TestCode()
{
}

void TestCode::testCoordinate()
{
	cout << endl << "Test Coordinate" << endl;
	Coordinate testCoordinate = Coordinate();
	cout << "Empty Coordinate : \t Lat : " <<
		testCoordinate.getLatitude() << "\t Long : " << testCoordinate.getLongitude() << endl;
	
	testCoordinate.setLatitude(90.0);
	testCoordinate.setLongitude(90.0);
	cout << "Set to 90.0, 90.0 Coordinate : \t Lat : " <<
		testCoordinate.getLatitude() << "\t Long : " << testCoordinate.getLongitude() << endl;

	cout << "Set to 90.0 radians Coordinate : \t Lat : " <<
		testCoordinate.getLatitudeRadians() << "\t Long : " << testCoordinate.getLongitudeRadians() << endl;

	cout << "Set Latitude outside of bounds" << endl;
	testCoordinate.setLatitude(300.0);
	cout << "Set Longitude outside of bounds" << endl;
	testCoordinate.setLongitude(300.0);

	cout << "To radians 180 : " << testCoordinate.toRadians(180) << endl;

	cout << endl << "Coordinate Tested." << endl;
}

void TestCode::testCity() {
	
	cout << endl << "Test City" << endl;

	City testCity = City();
	cout << "City Name : " << testCity.getCityName() << endl
		<< "City Country : " << testCity.getCityCountry() << endl
		<< "City Latitude : " << testCity.getCityCoordinates().getLatitude() << endl
		<< "City Longitude : " << testCity.getCityCoordinates().getLongitude() << endl;
	
	testCity.setCityName("Springdale");
	testCity.setCityCountry("USA");
	testCity.setCityCoordinates(36.1867, 94.1288);

	cout << "Springdale : " << testCity.getCityName() << endl
		<< "springdale : " << testCity.getLowerCaseCityName() << endl
		<< "USA : " << testCity.getCityCountry() << endl
		<< "Latitude : " << testCity.getCityCoordinates().getLatitude() << endl
		<< "Longitude : " << testCity.getCityCoordinates().getLongitude() << endl;

	cout << "Test Two City" << endl;
	City testTwoCity = City("Springdale", "USA", 36.1867, 94.1288);
	cout << "Springdale : " << testCity.getCityName() << endl
		<< "USA : " << testCity.getCityCountry() << endl
		<< "Latitude : " << testCity.getCityCoordinates().getLatitude() << endl
		<< "Longitude : " << testCity.getCityCoordinates().getLongitude() << endl;


	cout << endl << "City Tested." << endl;
}

void TestCode::testCityList()
{
	cout << endl << "Test CityList" << endl << endl;

	CityList testCityList = CityList();
	//testCityList.fillFromFile("TestFile.csv");
	testCityList.fillFromFile("WorldCities.csv");
	
	for (int index = 0; index < 9; index++) {
		City testCity = testCityList.getCity(index);
		cout << "City Name : " << testCity.getCityName() << endl
			<< "City Country : " << testCity.getCityCountry() << endl
			<< "City Latitude : " << testCity.getCityCoordinates().getLatitude() << endl
			<< "City Longitude : " << testCity.getCityCoordinates().getLongitude() << endl
			<< "City Index : " << testCity.getIndex() << endl;
	}

	cout << endl << "Closest Cities By Name : " << endl;
	vector<City> testVector = testCityList.getClosestCitiesByCityName("Aberdeen", 5);
	for (vector<City>::iterator it = testVector.begin(); it != testVector.end(); it++) {
		cout << it->getCityName() << endl;
	}

	cout << endl << "Closest Cities By Index : " << endl;
	vector<City> testVectorTwo = testCityList.getClosestCitiesByCityIndex(1, 5);
	for (vector<City>::iterator it = testVectorTwo.begin(); it != testVectorTwo.end(); it++) {
		cout << it->getCityName() << endl;
	}

	cout << endl << "Farthest Cities By Name : " << endl;
	vector<City> testVectorThree = testCityList.getFarthestCitiesByCityName("Aberdeen", 5);
	for (vector<City>::iterator it = testVectorThree.begin(); it != testVectorThree.end(); it++) {
		cout << it->getCityName() << endl;
	}

	cout << endl << "Farthest Cities By Index : " << endl;
	vector<City> testVectorFour = testCityList.getFarthestCitiesByCityIndex(1, 5);
	for (vector<City>::iterator it = testVectorFour.begin(); it != testVectorFour.end(); it++) {
		cout << it->getCityName() << endl;
	}

	City Springdale = City("Springdale", "USA",36.1867, 94.1288);
	City Fayetteville = City("Fayetteville", "USA", 36.0822, 94.1719);
	double testDistance = testCityList.getDistance(Springdale, Fayetteville);
	cout << "Test distance 12.25 : " << testDistance << endl;
	cout << endl << "CityList Tested." << endl;
}

void TestCode::testMenuIO()
{

}
