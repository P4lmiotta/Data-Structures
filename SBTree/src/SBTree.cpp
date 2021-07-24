//============================================================================
// Name        : SBTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "searchbinarytree.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	SBTree<char, int> tree;

	SBTNode<char, int> *n = tree.insertNode(4, 'd');
	tree.insertNode(1, 'a');
	tree.insertNode(2, 'b');
	tree.insertNode(3, 'c');
	tree.insertNode(5, 'e');
	tree.insertNode(6, 'f');
	tree.insertNode(7, 'g');

	tree.simmetricVisit(tree.Root());

	SBTNode<char,int> *sn = tree.lookupNode(tree.Root(), 6);


	if(sn != nullptr){
		cout << "Node found" << endl;
	} else {
		cout << "Node doesn't exist in the tree" << endl;
	}

	cout << "Remove Node 'f'" << endl;
	tree.removeNode(sn, tree.Key(sn));
	tree.simmetricVisit(n);

	SBTNode<char,int> *min = tree.min(tree.Root());
	cout << "Minimo: Key: " << tree.Key(min) << " - " <<"Value: " << tree.Value(min) << endl;

	SBTNode<char,int> *max = tree.max(tree.Root());
	cout << "Massimo: Key: " << tree.Key(max) << " - " <<"Value: " << tree.Value(max) << endl;



	return 0;
}
