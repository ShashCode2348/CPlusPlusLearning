#include <iostream>
#include "Person.h"
using namespace std;

void manipulate(double* pValue) {								//Recognises that the value entered is a pointer
	cout << "2. dValue(manipulate): " << *pValue << endl;
	*pValue = 10.0;												//Changes the value at the memory address(across the program)
	cout << "3. Value of double in manipulate: " << *pValue << endl;		//Uses * to de-reference tthe pointer
}

int main() {
	Person person1;
	Person person2("Bob", 42);
	Person person3("Sue", 25);
	cout << person1.toString() << "; memory location: " << &person1 << endl;
	cout << person2.toString() << "; memory location: " << &person2 << endl;
	cout << person3.toString() << "; memory location: " << &person3 << endl;
	/* --- */
	int nValue = 8;
	int* pnValue = &nValue;									//Memory address of nValue(* shows its a pointer, & assigns the
	cout << "Int value: " << nValue << endl;				//pointer)
	cout << "Pointer to int address: " << pnValue << endl;
	cout << "Int value via pointer: " << *pnValue << endl;  //Shows the value stored at the memory address(pointer) with the *
	//Usage
	double dValue = 123.4;
	cout << "1. dValue: " << dValue << endl;
	manipulate(&dValue);								//Sends the memory address to the function (& gets the address)
	cout << "4. dValue: " << dValue << endl;			//Changed here as well(as it was changed at the common memory address)
}
