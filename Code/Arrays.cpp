#include <iostream>
using namespace std;

int main() {
	//Arrays(list)
	int values[5];
	values[0] = 2; values[1] = 3; values[2] = 4; values[3] = 8;
	cout << values[0] << ' ' << values[1] << ' ' << values[2] << ' ' << values[3] << endl << '/n' << '\n' << values[4] << endl;
	//Shortcut for initiliasing variables in array
	double numbers[4] = { 4, 5, 2.7, 9.7 };
	cout << numbers[0] << endl << numbers[1] << endl << numbers[2] << endl << numbers[3] << endl;
	//Shortcut for outputting list
	for (int i = 0; i < 4; i = i + 1) {
		cout << numbers[i] << endl;
	}
	// Initialising with zero variables
	int nums[8] = {};
	for (int i = 0; i < 4; i = i + 1) {
		cout << nums[i] << endl;
	}
	//Further initialisation shortcut
	string texts[] = { "a", "b", "c" };
	for (int i = 0; i < 3; i = i + 1) {
		cout << texts[i] << endl;
	}
	// Even non-existent values can be accessed
	// cout << values[5] << endl;

	//Multi-dimensional arrays(arrays in arrays)
	// 2D Arrays
	string animals[2][3] = {							//Only the first number(2) can be missed out, the 2nd must be there
		{"fox", "dog", "cat"},
		{"mouse", "squirrel", "parrot"}
	};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << animals[i][j] << " " << flush;
		}
		cout << endl;
	}
	int multiplication[10][10] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{2, 4, 6, 8, 10, 12, 14, 16, 18, 20 },
		{3, 6, 9, 12, 15, 18, 21, 24, 27, 30},
		{4, 8, 12, 16, 20, 24, 28, 32, 36, 40},
		{5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
		{6, 12, 18, 24, 30, 36, 42, 48, 54, 60},
		{7, 14, 21, 28, 35, 42, 49, 56, 63, 70},
		{8, 16, 24, 32, 40, 48, 56, 64, 72, 80},
		{9, 18, 27, 36, 45, 54, 63, 72, 81, 90},
		{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
	};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << multiplication[i][j] << " " << flush;
		}
		cout << endl;
	}
	//Sizeof Arrays
	cout << sizeof(values) << endl;		//Sum of memory of all values(4*5=20)
	for (int i = 0; i < sizeof(values) / sizeof(int); i++) {
		cout << values[i] << " " << flush;
	}
	cout << endl;
	//Sizeof Multidimensional Arrays
	cout << sizeof(animals) << endl;
	cout << sizeof(animals[0]) << endl;
	for (int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++) {
		for (int j = 0; j < sizeof(animals[0]) / sizeof(string); j++) {
			cout << animals[i][j] << " " << flush;
		}
		cout << endl;
	}
	//Char Arrays
	char textArray[] = "hello";										//Stores it as {'h', 'e', 'l', 'l', 'o'} automatically
	for (int i = 0; i < sizeof(textArray); i++) {
		cout << i << ":" << (int)textArray[i] << endl;				//Has a length of 6, the last a char 0 used to tell when
	}																//the string ends
	int k = 0;
	while (true) {
		if (textArray[k] == 0) {
			break;
		}
		cout << textArray[k] << flush;
		k++;
	}
	cout << endl;
	//Reversing a string
	char text2[] = "Hello World!";
	int len = sizeof(text2) - 1;
	char* pStart = text2;
	char* pEnd = text2 + len - 1;
	while (pStart < pEnd) {
		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;
		pStart++;
		pEnd--;
	}
	cout << text2 << endl;
	return 0;
}
