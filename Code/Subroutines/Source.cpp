#include <iostream>
#include "Header.h"								//adds Header.h file to this file, the ifndef, define and endif are used 
using namespace std;							//if multiple files in a project include the header.h

void showMenu() {								//Function returns nothing
	cout << "1. Search" << endl;
	cout << "2. View Record" << endl;
	cout << "3. Quit" << endl;
}

int getInput() {						//Function returns int type value
	cout << "Enter selection: " << flush;
	int input;
	cin >> input;
	return input;
}

void processSelection(int choice) {										//takes an int type input for the function
	switch (choice) {
	case 1:
		cout << "Searching..." << endl;
		break;
	case 2:
		cout << "Viewing..." << endl;
		break;
	case 3:
		cout << "Quitting..." << endl;
	default:
		cout << "Please select an option from the menu. " << endl;
	}
}

void doSomething();									//Prototype, allows a function to be below where it is called

int main() {
	showMenu();
	int selection = getInput();
	processSelection(selection);
	doSomething();
	doSomething();
	something();
	return 0;
}

void doSomething() {
	cout << "Hello" << endl;
}

void something() {
	cout << "Something" << endl;
}
