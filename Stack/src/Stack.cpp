//============================================================================
// Name        : Stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Stack<int> pila;
	pila.push(1);
	pila.push(2);
	pila.push(3);
	pila.push(4);

	pila.print_pila();
	cout<<"----------------"<< endl;

	pila.pop();
	pila.print_pila();
	cout<<"----------------"<< endl;
	Stack<int> pila1 = pila;
	pila1.print_pila();
	return 0;
}
