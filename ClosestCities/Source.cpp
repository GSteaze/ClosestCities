#include <iostream>
#include "TestCode.h"
#include "MenuIO.h"

using namespace std;


void testCode() {
	TestCode test = TestCode();
	//test.testCoordinate();
	//test.testCity();
	test.testCityList();
}

int main() {
	

	testCode();

	//MenuIO menu = MenuIO();

	system("pause");
	return 0;
}
