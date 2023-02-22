#include <iostream>
using namespace std;

string numbers[] = { "one", "two", "three" };			//Can declare arrays here as well(like global array)

void show1(const int nElements, string texts[]) {
	cout << sizeof(texts) << endl;						//This returns size of pointer, loses array size
	for (int i = 0; i < nElements; i++) {
		cout << texts[i] << endl;
	}
}

void show2(string(&texts)[3]) {								//Passes arrays into the function retaining size info
	cout << sizeof(texts) << endl;
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++) {
		cout << texts[i] << endl;
	}
}

char* getMemory() {										//Usually come in pairs to create and deallocate memory
	char* pMem = new char[100];
	return pMem;
}

void freeMemory(char* pMem) {
	delete[] pMem;
}

int main() {
	string texts[] = { "apple", "orange", "banana" };
	cout << sizeof(texts) << endl;
	show1(3, texts);
	show2(texts);
	char* pMemory = getMemory();
	freeMemory(pMemory);
	return 0;
}
