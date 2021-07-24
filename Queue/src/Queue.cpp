//============================================================================
// Name        : Queue.cpp
// Author      : Alessandro Palmiotta
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Queue<int> coda;
	coda.push(1);
	coda.push(2);
	coda.push(3);
	coda.push(4);
	coda.printQueue();
	cout<< "-------------"<<endl;
	coda.pop();

	cout<< "-------------"<<endl;
	coda.printQueue();
	cout<< "-------------"<<endl;
	Queue<int> coda1 = coda;
	coda1.printQueue();
	return 0;
}
