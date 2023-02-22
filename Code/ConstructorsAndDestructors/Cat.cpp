#include <iostream>
#include <sstream>
#include "Cat.h"
using namespace std;

Cat::Cat() {
	cout << "Cat created." << endl;
	happy = true;
}

Cat::~Cat() {
	cout << "Cat destroyed." << endl;
}

void Cat::speak() {
	if (happy) {
		cout << "Meow!" << endl;
	}
	else {
		cout << "Ssss..." << endl;
	}
}

Person::Person() {
	name = "George";
}

string Person::toString() {
	return "Person's name is " + name;
}

void Person::setName(string newName) {
	name = newName;
}

string Person::getName() {
	return name;
}

People::People() {
	name = "undefined";
	age = 0;
}

string People::toString() {
	stringstream ss;
	ss << "Name: " << name << "; Age: " << age;
	return ss.str();
}
