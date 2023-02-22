#include <iostream>
using namespace std;

class Animal {
private:
	string name;
public:
	Animal() { cout << "Animal created." << endl; }
	Animal(const Animal& other) : name(other.name) { cout << "Animal created by copying." << endl; }
	~Animal() { cout << "Destructor called." << endl; }
	void setName(string name) { this->name = name; }
	void speak() { cout << "My name is " << name << endl; }
};
//Returning objects from function(using new)
Animal createAnimal() {							//less efficient(creates temporary copies), but does not require deleting
	Animal a;
	a.setName("Bertie");
	return a;
}

Animal* createAnimal2() {						//more efficient, requires deleting though
	Animal* pAnimal = new Animal();
	pAnimal->setName("Bertie");
	return pAnimal;
}

int main() {
	//new
	Animal* pCat1 = new Animal();		//This won't be destroyed out of scope automatically, always delete it when new used(can be done on any type)
	pCat1->setName("Freddy");			//Special syntax between pointers to objects and its functions
	pCat1->speak();
	delete pCat1;						//Note: Use long long int when subtracting pointers as they have same amount of memory
	//Returning objects from methods(using new)
	Animal frog = createAnimal();
	frog.speak();
	Animal* pBird = createAnimal2();
	pBird->speak();
	delete pBird;
	//Alllocating Memory
	Animal* pAnimal = new Animal[10];			//Creates 10 Animals(usable on any type, e.g. char, string, int)
	pAnimal[5].setName("George");
	pAnimal[5].speak();
	delete[] pAnimal;							//Deletes all objects at the address
	Animal* pAlphabet = new Animal[26];			//Ex 1
	for (int i = 0; i < 26; i++) {
		string name(1, (i + 97));
		pAlphabet[i].setName(name);
		pAlphabet[i].speak();
	}
	delete[] pAlphabet;
	//Bitwise And
	int colour = 0x123456;
	unsigned char red = (colour & 0xFF0000) >> 16;
	unsigned char green = (colour & 0x00FF00) >> 8;
	unsigned char blue = colour & 0x0000FF;
	//Bitwise and (&): In binary, if both digits in the numbers are 1, then the resultant digit will be 1
	/*
	colour: 000100100011010001010110
	mask:   111111110000000000000000
	result: 000100100000000000000000
	*/
	cout << hex << (int)red << endl << (int)green << endl << (int)blue << endl;
	//Also works(just for red though, as discards the rest)
	unsigned char redAgain = colour >> 16;
	cout << hex << (int)redAgain << endl;
	//Bitwise or (|): if either the value or mask have digit 1 in binary, the resulting digit is 1
	return 0;
}
