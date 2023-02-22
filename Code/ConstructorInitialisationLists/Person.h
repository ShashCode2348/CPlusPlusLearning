#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person() : name(""), age(0) {};
	Person(string name, int age);
	string toString();
};

#endif /* PERSON_H_ */
