#include <iostream>
#include "Cat.h"
using namespace std;

//Copy Constructors(this class and below)
class Animal {
private:
	string name;
public:
	Animal() { cout << "Animal created." << endl; }			//Only called once, because when animal2 created,
	//doesn't run as the Copy Constructor is run instead, called when = used in intialisation
	Animal(const Animal& other) : name(other.name) { cout << "Animal created by copying." << endl; other.speak(); }
	//Other is the object after = only time other object's values can be accessed, is done by default
	//Overrun normal Copy Constructor(shown by syntax, name(other.name) not needed ; const functions can be used on other object
	void setName(string name) { this->name = name; }
	void speak() const { cout << "My name is " << name << endl; }
};

int main() {
	cout << "Starting program..." << endl;
	//{										//One way to contain an object to a certain range(not common).
	//	Cat bob;
	//	bob.speak();
	//}										//Object destroyed after exiting curly brackets
	cout << "Ending program..." << endl;
	Person person;										//Person class for Getters and Setters
	person.setName("Georgina");
	cout << person.toString() << endl;
	cout << "Name of person with get method is " << person.getName() << endl;
	People person1;
	cout << person1.toString() << endl;
	People person2("Bob");
	cout << person2.toString() << endl;					//Two constructors, person2 has a string parameter, runs constructor
	People person3("Sue", 35);						    // which correspond. Must differ in parameter type,
	cout << person3.toString() << endl;				    //return type cannot differentiate constructors
	//Copy Constructors(see here and above Animal class)
	Animal animal1;
	animal1.setName("Freddy");
	Animal animal2 = animal1;							//Copies the values of animal1's variables
	animal2.setName("Bob");								//animal2 is a new object, so is independent of animal1 and its
	animal1.speak();									//variables can be changed
	animal2.speak();
	Animal animal3(animal1);							//() call = , calling Copy Constructor 
	animal3.speak();
	return 0;
}
