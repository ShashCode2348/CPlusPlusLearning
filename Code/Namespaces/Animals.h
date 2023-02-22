#ifndef ANIMALS_H_
#define ANIMALS_H_
#include <iostream>
using namespace std;

namespace shp {						//defines shp namespace
	const string CATNAME = "Tiddles";
	class Cat {
	public:
		Cat();
		virtual ~Cat();
		void Speak();
	};

} /* namespace shp */

#endif /* ANIMALS_H_ */
