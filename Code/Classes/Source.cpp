#include <iostream>
#include "Smth.h"
using namespace std;

int main() {
	Speak speak;			//Defines object from class
	speak.qwerty();			//Uses dot notation to access function through object
	speak.hi();
	return 0;
}
