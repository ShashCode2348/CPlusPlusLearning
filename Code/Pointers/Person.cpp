#include <iostream>
#include <sstream>
#include "Person.h"
using namespace std;

Person::Person() {
	age = 0;
	name = "";
}

Person::Person(string name, int age) {
	this->name = name;					//use this-> to refer to the name assigned to the object, rather than the parameter
	this->age = age;
	cout << "Memory location of object: " << this << endl; //the hex number of the computer's memory allocated to the object
}


string Person::toString() {
	stringstream ss;
	ss << "Name: " << name << "; Age: " << age;
	return ss.str();
}
