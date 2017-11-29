#include "MenuIO.h"



void MenuIO::displayWelcomeMessage()
{
	cout << "Welcome to Closest Cities!" << endl << endl;
}

MenuIO::MenuIO()
{
	cities.fillFromFile("WorldCities.csv");
	displayWelcomeMessage();
	displayMenu();
}


MenuIO::~MenuIO()
{
}

void MenuIO::displayMenu()
{
	bool isAgain = true;
	while (isAgain) {
		cout << endl << "Menu" << endl;
		cout << "1. Closest Cities" << endl
			<< "2. Farthest Cities" << endl
			<< "3. Close Program" << endl;

		int userSelection = intValidator(kMenuOptionMinimum, kMenuOptionMaximum);
		cout << endl;

		vector<City> cityResults;
		int indexOrNameForClosest = 0;
		int indexOrNameForFarthest = 0;
		int cityIndexForClosest = 0;
		int cityIndexForFarthest = 0;
		string cityNameForClosest = "";
		string cityNameForFarthest = "";
		int counterForClosest = 0;
		int counterForFarthest = 0;
		switch (userSelection) {
		case 1:
			indexOrNameForClosest = userSelectsIndexOrCityName();
			if (indexOrNameForClosest == 1) {
				cityIndexForClosest = intValidator(0, kMaximumIndexNumber);
				cityResults = cities.getClosestCitiesByCityIndex(cityIndexForClosest, kNumberOfCityResults + 1);
			}
			else if (indexOrNameForClosest == 2) {
				cityNameForClosest = stringValidator("the City Name");
				cityResults = cities.getClosestCitiesByCityName(cityNameForClosest, kNumberOfCityResults + 1);
			}
			cout << "Closest Cities : " << endl;
			counterForClosest = 1;
			for (vector<City>::iterator it = cityResults.begin() + 1; it != cityResults.end(); it++) {
				cout << counterForClosest << ". " << it->getCityName() << endl;
				counterForClosest++;
			}
			cityResults.clear();
			break;
		case 2:
			indexOrNameForFarthest = userSelectsIndexOrCityName();
			if (indexOrNameForFarthest == 1) {
				cout << "Enter the index of the desired city : ";
				int cityIndex = intValidator(0, kMaximumIndexNumber);
				cityResults = cities.getFarthestCitiesByCityIndex(cityIndex, kNumberOfCityResults);
			}
			else if (indexOrNameForFarthest == 2) {
				cityNameForFarthest = stringValidator("the City Name");
				cityResults = cities.getFarthestCitiesByCityName(cityNameForFarthest, kNumberOfCityResults);
			}
			cout << "Farthest Cities : " << endl;
			counterForFarthest = 1;
			for (vector<City>::iterator it = cityResults.begin(); it != cityResults.end(); it++) {
				cout << counterForFarthest << ". " << it->getCityName() << endl;
				counterForFarthest++;
			}
			cityResults.clear();
			break;
		case 3: cout << "Program Closing." << endl;
			isAgain = false;
			break;
		default: cout << "Invalid Selection." << endl;
			break;
		}
	}
}

int MenuIO::userSelectsIndexOrCityName() {
	cout << "Search by : " << endl
		<< "1. Index" << endl
		<< "2. Name of City" << endl;
	int userSelection = intValidator(1, 2);
	return userSelection;
}

int MenuIO::intValidator(int min, int max)
{
	cout << "Enter a number between " << min << " and " << max << " : ";
	int userInput = 0;
	bool isValidInput = false;
	while (!isValidInput) {
		cin >> userInput;
		if (cin.fail() || userInput < min || userInput > max) {
			cout << "Please try again : ";
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
		}
		else if (userInput >= min && userInput <= max) {
			isValidInput = true;
		}
	}
	return userInput;
}

string MenuIO::stringValidator(string desiredField)
{
	cout << "Please enter " << desiredField << " : ";
	string userInput = "";
	cin.ignore(kEndOfLine, '\n');
	getline(cin, userInput);

	bool isValid = false;
	while (!isValid) {
		if (userInput.empty()) {
			cout << "Phrase cannot be empty." << endl
				<< "Please try again : ";
			cin.clear();
			getline(cin, userInput);
		}
		else {
			isValid = true;
		}
	}
	return userInput;
}
