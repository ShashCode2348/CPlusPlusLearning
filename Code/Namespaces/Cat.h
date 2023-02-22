#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
using namespace std;

namespace cats {

	const string CATNAME = "Freddy";			//Global variable which is part of the namespace

	class Cat {
	public:
		Cat();
		virtual ~Cat();
		void Speak();
	};
}  /* namespace cats */
#endif /* HEADER_H_ */
