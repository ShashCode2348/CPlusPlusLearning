#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string name = "Bob";
	int age = 32;
	stringstream ss;
	ss << "Name: " << name << "; Age: " << age;				//Allows string and other types to be concatenated
	cout << ss.str() << endl;
	return 0;
}
