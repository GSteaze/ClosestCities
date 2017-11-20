#include "MenuIO.h"



void MenuIO::displayWelcomeMessage()
{
	cout << "Welcome to Closest Cities!" << endl << endl;
}

MenuIO::MenuIO()
{
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

		switch (userSelection) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
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
