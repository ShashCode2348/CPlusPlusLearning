#include <iostream>
using namespace std;

int main() {
	string texts[] = { "one", "two", "three" };
	string* pTexts = texts;									//pointers and arrays are very similar, just arrays know how 
	cout << sizeof(texts) / sizeof(string) << endl;		   //much data they hold, but pointers know only that of the first item
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++) {
		cout << pTexts[i] << " " << flush;
	}
	cout << endl;
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++, pTexts++) {	//pTexts will now refer to the next value in list 
																			//with increment
		cout << *pTexts << " " << flush;						//Without next line this would output the first string only.
	}
	cout << endl;
	cout << *pTexts << endl;								//Now it refers to the non-existent 4th value, so outputs nothing
	string* pElement = texts;								//Gets the address of the first element in the array
	string* pEnd = &texts[2];								//Gets the address of the last element in the array
	while (true) {
		cout << *pElement << " " << flush;
		if (pElement == pEnd) {
			break;
		}
		pElement++;
	}														//Another way to loop through an array
	return 0;
}
