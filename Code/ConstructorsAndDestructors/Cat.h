#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;

class Cat {
private:
	bool happy;
public:
	void speak();
	Cat();
	~Cat();
};

class Person {
private:
	string name;
public:
	Person();
	string toString();
	void setName(string newName);
	string getName();
};

class People {
private:
	string name;
	int age;
public:
	People();
	People(string newName) { name = newName; age = 0; };
	People(string newName, int newAge) { name = newName; age = newAge; };
	string toString();
};

#endif /* CAT_H_ */
