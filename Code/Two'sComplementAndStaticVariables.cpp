#include <iostream>
using namespace std;

//Normally in .h file
class Test {
private:
	int id;
	static int count;			//shared with all objects of class(must be initialised elsewhere. Can only be used
								//in class if public)
public:
	Test() { id = count++; }	//This sets id to value of count, then increments it(postfix method).
	int getId() { return id; }	//If it was 'id = ++count;', then increments before setiing value(prefix method).
	static int const MAX = 99;	//for constants, must give value when declared
	static void showInfo() {	//can only access static variables
		cout << count << endl;	//don't need prefix when in class documentation
	}
};

//normally in .cpp source file
int Test::count = 0;			//can be used anywhere

int main() {
	//Two's Complement
	char value = 127;				//Max value for char(range is from -128 to 127(as 0 is considered positive))
	cout << (int)value << endl;
	value++;						//Loops back to -128
	cout << (int)value << endl;
	/*
	3-bit system:
	Unsigned: Min is 0, Max = bin(111) = 7 = 2^3 - 1
	Signed: Min is -(2^2) = -4, Max is 2^2 - 1 = 3
	One's Complement:
	000 = 0
	001 = 1
	010 = 2
	011 = 3
	100 = -3
	101 = -2
	110 = -1
	111 = -0
	The first character is always the sign(1 negative, 2 positive)
	001 (1)  +
	110 (-1) =
	111 (-0 = 0) right answer

	0011 (3) +
	0101 (-2) =
	1000 (8) wrong answer
	Rule: add overflow bit to right
	000 + 1 = 001 = 1		right answer
	Not used nowadays due to wastage of place(two 0's) and overflow bit rule

	Two's Complement(used nowadays):
	000 = 0
	001 = 1
	010 = 2
	011 = 3
	100 = -4		goes negative
	101 = -3
	110 = -2
	111 = -1
	Advantages
	1. Only one 0
	2. Easier arithmetic
	e.g.
	0010 (2) +
	0110 (-2) =
	1000 -> discard overflow bit to get the answer
	000 = 0

	010 (2) +
	101 (-3) =
	111 (-1) right answer

	010 (2) +
	011 (3) =
	101 (-3) right answer using mod (2 + 3 = 5 = -3(mod 8)
	*/


	//Static Keyword(look at class Test)
	Test::showInfo();
	cout << Test::MAX << endl;		//prefix to access class static variables
	Test test1;
	Test test2;
	Test::showInfo();
	cout << "Object 1 ID: " << test1.getId() << endl;
	cout << "Object 2 ID: " << test2.getId() << endl;
	return 0;
}
