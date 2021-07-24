//============================================================================
// Name        : List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * main.cpp
 *
 *  Created on: 17 apr 2020
 *      Author: pc
 */
#include <iostream>
#include "linked_list.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	List<int> ll;
	ll.pushBack(2);
	ll.pushBack(3);
	ll.pushBack(0);
	ll.pushFront(1);

	ll.printList();

		ll.insert(ll.find(2), 6);

		ll.printList();

		ll.erase(ll.find(2));

		ll.printList();

	return 0;
}
