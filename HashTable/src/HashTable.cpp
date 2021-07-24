//============================================================================
// Name        : HashTable.cpp
// Author      : Alessandro Palmiotta
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HashTable\src\hash.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	HashTable<char, int> HTable(15);



	cout << "!!!Hello World!!!" << endl;


	HTable.inserisci('a', 1);
	HTable.inserisci('b', 2);
	HTable.inserisci('c', 5);
	HTable.inserisci('d', 6);


	cout << "!!!Hello World!!!" << endl;
	cout << HTable << endl;
	return 0;
}
