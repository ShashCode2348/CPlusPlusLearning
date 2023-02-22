#include <iostream>
using namespace std;

/*
This is a multi-line comment
Conditional operators met so far are:
== equals
!= not equals
< less than
> more than
New operators
<= less than or equal to
>= more than or equal to
To combine conditions
&& logical and
|| logical or
*/
int main() {
	cout << "How's Life?" << endl;
	short value1 = 0;
	short value2 = 0;
	cout << "Enter for Value 1: " << flush;
	cin >> value1;
	cout << "Enter for Value 2: " << flush;
	cin >> value2;
	if (value1 < 8) {
		cout << "Value 1 less than 8" << endl;
	}
	if (value2 <= 4) {
		cout << "Value 2 less than or equal to 4" << endl;
	}
	if (value1 == 7 && value2 >= 3) {
		cout << "Value 1 equal to 7 and Value 2 more than or equal to 3" << endl;
	}
	if (value1 != 7 || value2 == 3) {
		cout << "Value 1 not equal to 7 or Value 2 equal to 3" << endl;
	}
	if (value2 != 8) {
		cout << "Value 2 not equal to 8" << endl;
	}
	else {
		cout << "Value 2 equal to 8" << endl;
	}
	if (value2 != 4 && value1 <= 7 || value1 >= 10) {
		cout << "Condition met" << endl;
	}
	// The above condition says if (value2 != 7 && value1 <= 7) is true OR value1 >= 10 is true True is returned.
	// To help read parenthesis could be used OR the below
	bool condition1 = (value2 != 4) && (value1 <= 7);
	cout << condition1 << endl;
	bool condition2 = (value1 >= 10);
	cout << condition2 << endl;
	if (condition1 || condition2) {
		cout << "Condition 2 met" << endl;
	}
	return 0;
}
