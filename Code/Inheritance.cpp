#include <iostream>
using namespace std;

class Animal {										//Superclass of Cat
public:
	void speak() { cout << "Grrr..." << endl; }
};

class Cat :public Animal {							 //Inheritance: Cat is a subclass of Animal, and gets all its 
public:												//functions and variables
	void jump() { cout << "Cat jumping" << endl; } //An addition to the Cat class which wasn't in the Animal class
};

class Tiger : public Cat {							//Subclass of Cat. Inherits Cat's functions, which inherited
public:												//Animal's functions
	void attackAntelope() { cout << "Attacking" << endl; }
};

class Frog {							//private and public secctions can be in any order, and can be more of them
private:								//This is encapsulated, if it wasn't, then could be accessed outside
	string name;						//and many objects would be setting each other's data, making a mess
	string getName() { return name; }	//Try to make anything you can private(functions or data)
public:
	Frog(string name) : name(name) {}	//Can access the private(encapsulated) variables through functions
	void info() { cout << "My name is: " << getName() << endl; }	//Can access private functions, as private 
};																 //variables can be accessed in class documetation

class Machine {
private:
	int id;						//This can only be referred to in this class, but subclass objects also have this
public:
	Machine() : id(0) { cout << "Machine no-argument constructorr called" << endl; }
	Machine(int id) : id(id) { cout << "Machine parameterised constructor called" << endl; }
	void info() { cout << "ID: " << id << endl; }
};

class Vehicle :public Machine {					//When creating an object of a subclass, the constructors of
public:											//its superclasses are called as well in order
	Vehicle() { cout << "Vehicle" << endl; }
	Vehicle(int id) : Machine(id) { cout << "Vehicle parameterised constructor called" << endl; }
};			//Above allows superclass variables to be accessed

class Car :public Vehicle {
public:
	Car() { cout << "Car no-argument constructor called." << endl; }
	Car(int id) : Vehicle(id) { cout << "Vehicle parameterised constructor called" << endl; }
};				//Above: Only direct superclasses an be referred to

int main() {
	//Inheritance(classes 1-3)
	Animal a;
	a.speak();
	Cat cat;
	cat.speak();
	cat.jump();
	Tiger tiger;
	tiger.speak();
	tiger.jump();
	tiger.attackAntelope();
	//Encapsulation(class 4)
	Frog frog("Freddy");
	frog.info();
	//Constructor Inheritance(classes
	Machine machine;
	Vehicle vehicle;
	Car car;						//All 3 constructors called
	//Vehicle vehicle(123);			Constructors from superclasses are run but not inherited(see line 40 to solve)
	Vehicle vehicle1(123);
	vehicle1.info();
	Car car1(999);
	car1.info();
	return 0;
}
