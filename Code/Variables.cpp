#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void changeSomething(double& value) {
	value = 123.4;
}

class Animal {
private:
	string name;
public:
	void setName(string name) { this->name = name; };
	void speak() const { cout << "My name is " << name << endl; }			//Nothing can be changed in this function
};

int main() {
	// intro
	cout << "Starting program..." << flush;
	cout << "Hi" << endl;
	cout << "How\'s life?" << endl;
	cout << "Life\'s " << "good" << endl;
	int numberInt = 5;
	int anotherNumber = 7;
	int sumNumbers = numberInt + anotherNumber;
	cout << "The number is " << numberInt << endl;
	cout << "Another number is " << anotherNumber << endl;
	cout << "The sum is " << sumNumbers << endl;
	anotherNumber += 1;
	cout << "Another number is now " << anotherNumber << endl;
	cout << "The new sum is " << sumNumbers << endl;
	// strings
	string aString = "This is ";
	string bString = "a string. ";
	string cString = aString + bString;
	cout << aString << bString << endl;
	cout << cString << endl;
	cout << "Enter your name: " << flush;
	string name;
	cin >> name;
	cout << "Hello " << name << endl;
	short aNumber = 8;
	cout << "Enter a number: " << flush; cin >> aNumber;
	cout << "The number you entered is " << aNumber << endl;
	// integers
	int bigValue = 123456789987654567;
	cout << bigValue << endl;
	cout << "Maximum integer value is " << INT_MAX << " and the minimum integer value is " << INT_MIN << endl;
	long long int longValue = 2345325345345;
	cout << longValue << endl;
	unsigned int uValue = 9876;
	cout << uValue << endl;
	long int fValue = 21400000000;
	cout << fValue << endl;
	cout << fixed << fValue << endl;
	// floats
	float flValue = 76.4;
	cout << sizeof(float) << endl;
	cout << scientific << flValue << endl;
	cout << setprecision(20) << fixed << flValue << endl;
	double dValue = 76.4;
	cout << sizeof(double) << endl;
	cout << scientific << dValue << endl;
	cout << setprecision(20) << fixed << dValue << endl;
	float fllValue = 123.45678912345678912;
	cout << scientific << fllValue << endl;
	cout << setprecision(20) << fixed << fllValue << endl;
	long double ddValue = 123.45678912345678912;
	cout << sizeof(long double) << endl;
	cout << scientific << ddValue << endl;
	cout << setprecision(20) << fixed << ddValue << endl;
	// boolean
	bool bValue = true;
	cout << bValue << endl;
	bool bValue1 = false;
	cout << bValue1 << endl;
	bool bValue2 = 43;
	cout << bValue2 << endl;
	bool bValue3 = 42;
	cout << bValue3 << endl;
	// char
	char cValue = 55;
	cout << cValue << endl;		//relates to the ASCII Symbols
	char cValue1 = '7';
	cout << cValue1 << endl;
	cout << (int)cValue1 << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	wchar_t wValue = 'i';
	cout << (char)wValue << endl;
	cout << "Size of wchar_t: " << sizeof(wchar_t) << endl;
	//References
	int value1 = 8;
	int& value2 = value1;										//The & keeps the two always equal, and value2 is a reference
	value2 = 10;												//to value1, another name to the same variable, a synonym to it
	cout << "Value 1: " << value1 << endl; cout << "Value 2: " << value2 << endl;		//can be done to all data types
			//Can be used in functions(see the top), e.g.
	double value = 4.321;
	changeSomething(value);
	cout << setprecision(4) << value << endl;
	//const keyword(see top for Animal class)
	const int value3 = 7;
	cout << value3 << endl;
	Animal animal;
	animal.setName("Freddy");
	animal.speak();
	int value4 = 8;
	const int* pValue4 = &value4;//If line was 'int* const pValue4 = &value4', then can't point pointer elsewhere and the below
	cout << *pValue4 << endl;			//can't change what the pointer points to via the pointer
	int num = 11;
	pValue4 = &num;
	//*pValue4 = 12;							//Does not work as tries to change through the pointer
	cout << *pValue4 << endl;
	pValue4 = &value4;
	num = 12;							//Pointer no longer points at num, can be changed
	cout << num << endl;				//A trick to understand variables is reading them backwards
	return 0;							//e.g. const int* pValue4 is a pointer to an int that cannot be changed(the int can't)
}
