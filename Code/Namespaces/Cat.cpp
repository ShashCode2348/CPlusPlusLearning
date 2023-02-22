#include "Cat.h"						//As Cat.h is put into here, #include <iostream> and using namespace std;
// 										  are only needed in Cat.h, Same in Animals.cpp
namespace cats {
	Cat::Cat() {
		//
	}

	Cat::~Cat() {
		//
	}

	void Cat::Speak() {
		cout << "Meow" << endl;
	}
}
