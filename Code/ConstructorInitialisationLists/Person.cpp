#include <iostream>
#include <sstream>
#include "Person.h"
using namespace std;

//Constructor Initialisation Lists
// //Can initialise variables, use if initialising with
//parameters or values, else use something like this' method
//Can also be initialised in the prototype without a definition(see Person.h)

Person::Person(string name, int age) : name(name), age(age) {

}


string Person::toString() {
	stringstream ss;
	ss << "Name: " << name << "; Age: " << age;
	return ss.str();
}
