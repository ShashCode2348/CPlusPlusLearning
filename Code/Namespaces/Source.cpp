#include <iostream>
#include "Cat.h"
#include "Animals.h"
using namespace std;
using namespace shp;

int main() {
	cats::Cat cat;			//how to access classes without the using namespace statement(namespace_name::class)
	cat.Speak();
	Cat cat2;				//uses shp namespace as its using statement is there
	cat2.Speak();
	shp::Cat cat3;			//Can still use this syntax even if namespace included
	cat3.Speak();
	cout << shp::CATNAME << endl;
	cout << cats::CATNAME << endl;
	cout << CATNAME << endl;
	return 0;
}
