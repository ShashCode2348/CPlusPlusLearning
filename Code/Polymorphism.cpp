#include <iostream>
using namespace std;

class Animal {
public:
	void speak1() { cout << "???" << endl; }
	virtual void speak() = 0;		//This forces subclasses to have a speak method(an abstract/pure virtual method)
	virtual ~Animal() {};							//Destructors should generally be made virtual
};

class Cat : public Animal {
public:
	void speak1() { cout << "RrrrrRRRrrrr" << endl; }
	void speak() { cout << "RrrrrRRRrrrr" << endl; }
	virtual ~Cat() {};
};

class HouseCat :public Cat {
public:
	void speak() { cout << "Meow" << endl; }
	virtual ~HouseCat() {};
};

int main() {
	Animal* pAnimal = new Cat;  //Subtype Polymorphism: In a pointer or reference to a base class, a subtype can be used
	pAnimal->speak1();			//The pointer is of type Animal, so base class method used
	pAnimal->speak();			//speak is declared virtual, so it is overridden
	delete pAnimal;
	return 0;
}
