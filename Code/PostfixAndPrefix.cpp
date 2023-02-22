#include <iostream>
using namespace std;

int main() {
	int value = 8;
	value++;					//Postfix form(for addition)
	cout << value << endl;
	++value;					//Prefix form(for addition)
	cout << value << endl;
	value--;
	cout << value << endl;
	--value;
	cout << value << endl;
	//Difference between postfix and prefix
	cout << value++ << endl;			//Uses and then increments it
	cout << value << endl;
	cout << ++value << endl;			//Increments then uses it
	int number = value; //Sets number to value then increments value(++value would increment value then set number to it)
	cout << value << endl;
	return 0;
}
