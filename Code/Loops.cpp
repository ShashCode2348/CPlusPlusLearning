#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// If, Else If and Else
	string password = "How'sYou?";
	cout << "Enter the password for If Else(How'sYou?) > " << flush;
	string input = "";
	cin >> input;
	cout << "You entered " << "'" << input << "'" << endl;
	if (input == password) {
		cout << "Password accepted. " << endl;
		cout << "1.\tAdd new record " << endl;
		cout << "2.\tDelete record " << endl;
		cout << "3.\tView record " << endl;
		cout << "4.\tSearch record " << endl;
		cout << "5.\tQuit " << endl;
		cout << "Enter your selection > " << flush;
		int choice;
		cin >> choice;
		if (choice < 3) {
		cout << "Insufficient privileges to perform action" << endl;
		}
		else if (choice == 3) {
			cout << "Loading record..." << endl;
		}
		else if (choice == 4) {
			cout << "Searching records" << endl;
		}
		else if (choice == 5) {
			cout << "Application quitting..." << endl;
		}
		else {
			cout << "Invalid option." << endl;
		}
	}
	if (input != password) {
		cout << "Access denied." << endl;
	}
	//Comparing floats
	double value1 = 1.1;
	if (value1 == 1.1) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}
	cout << setprecision(10) << value1 << endl;
	double value2 = 1.2;
	if (value2 < 1.21) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}
	cout << setprecision(10) << value2 << endl;

	// While
	short abc = 0;
	while (abc < 5) {
		cout << abc << endl;
		abc++;
	}
	/*
	Infinite loops
	while (true) {
		cout << "Hello" << endl;
	}
	*/
	// While
	string password2 = "SSS";
	cout << "Enter the password for While(SSS) > " << flush;
	string input2 = "";
	cin >> input2;
	cout << "You entered " << "'" << input2 << "'" << endl;
	if (input2 == password2) {
		short i = 0;
		while (i < 6) {
			cout << "Hello " << i << endl;
			i++;       // increments by 1: i = i + 1 also works
		}             // executes 6 times
	}
	/*
	Do While. Do While loops are different to while loops as they run at least once, 
	as they evaluate the while expression after running
	*/
	const string pwd = "bwuh";
	string password3 = "Waht?";
	string qwerty;
	string abcdef;
	cout << "Enter the password for Do While(Waht?) " << flush;
	cin >> qwerty;
	cout << "You entered " << "'" << qwerty << "'" << endl;
	if (qwerty == password3) {
		cout << "Do While: 8 lines" << endl;
		do {
			cout << "Enter the password(bwuh) " << flush;
			cin >> abcdef;
			if (abcdef != pwd) {
				cout << "Access denied" << endl;
			}
		} while (abcdef != pwd);
		cout << "Password accepted" << endl;
		cout << "While: 10 lines" << endl;
		cout << "Enter the password(bwuh) " << flush;
		cin >> abcdef;
		while (abcdef != pwd) {
			cout << "Enter the password(bwuh) " << endl;
			cin >> abcdef;
			if (abcdef != pwd) {
				cout << "Access denied" << endl;
			}
		}
		cout << "Password accepted" << endl;
	}
	//For loops
	/*
	Infinite for loops:
	for ( ; ; ) {
		cout << "Hello" << endl;
	}
	*/
	const string password4 = "smth";
	string answer4;
	cout << "Enter password for For Loops(smth) " << flush;
	cin >> answer4;
	if(password4 == answer4) {
		for (int i = 0; i < 10; i++) {   // repeats 10 times(uses start, end, increment)
			cout << i << endl;
		}
	}
	//Break and Continue
	const string password5 = "idk";
	string answer5;
	cout << "Enter password for Break and Continue(idk) " << flush;
	cin >> answer5;
	if (password5 == answer5) {
		cout << "break" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "i is " << i << endl;
			if (i == 3) {
				break;						//Exits the loop immediately
			}
			cout << "Looping..." << endl;
		}
	}
	if (password5 == answer5) {
		cout << "Continue" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "i is " << i << endl;
			if (i == 3) {
				continue;						//Exits the current repeat of the loop immediately
			}
			cout << "Looping..." << endl;
		}
	}
	if (password5 == answer5) {
		cout << "Usage of break(from Do-While Loops)" << endl;
		do {
			cout << "Enter the password(bwuh) " << flush;
			cin >> abcdef;
			if (abcdef == pwd) {
				break;
			}
			else {	
				cout << "Access denied" << endl;
			}
		} while (true);
	}
	//Switch
	const string password6 = "qwerty";
	string answer6 = "";
	cout << "Enter password for Switch(qwerty): " << flush;
	cin >> answer6;
	if (password6 == answer6) {
		int abcdef = 5;
		switch (abcdef) {
		case 4:				
			cout << "Value is 4" << endl;			//Equivalent of if statements
			break;
		case 5:
			cout << "Value is 5" << endl;
			break;
		case 6:
			cout << "Value is 6" << endl;
			break;
		default:									//Equivalent of else statements
			cout << "Unrecognised value" << endl;
		}										//Cases cannot be variables, but const type can be used. 
	}										   //Break should be used after end of each case, else other cases will be executed
	return 0;
}
