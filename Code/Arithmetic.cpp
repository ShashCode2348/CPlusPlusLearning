#include <iostream>
using namespace std;

int main() {
	double value1 = (double)7 / 2;					//Casting, keeps the remainder(without the (double) you get value with removed remainder
	cout << value1 << endl;

	/* --- */
	int value3 = 9;
	value3 += 1;					//like in Python
	cout << value3 << endl;

	value3 *= 2;
	cout << value3 << endl;

	value3 /= 3;
	cout << value3 << endl;

	value3 %= 4;					//modulo, like in Python
	cout << value3 << endl;

	double equation = 5.3 / 4 + 2 * 6;	//C++ uses BODMAS in solving equations. Better to use brackets in more complex equations.
	cout << equation << endl;

	/* Exercises */
	//1. Minutes, hours, seconds
	int secondsInput;
	cout << "Enter number of seconds(integer): " << flush; cin >> secondsInput;
	int hours = (secondsInput - (secondsInput % 3600)) / 3600;
	int seconds = secondsInput - hours * 3600;
	int minutes = (seconds - seconds % 60) / 60;
	seconds -= (60 * minutes);
	cout << "In hours, minutes and seconds, " << secondsInput << " -> " << hours << ":" << minutes << ":" << seconds << endl;
	//Use for loop to iterate 10,000 times, but output a dot every 100 iterations
	for (int i = 0; i < 10000; i++) {
		if ((i % 100) == 0) {
			cout << "." << flush;
		}
	}
	return 0;
}
