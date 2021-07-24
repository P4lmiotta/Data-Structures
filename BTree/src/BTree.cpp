//============================================================================
// Name        : BTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "binarytree.h"
using namespace std;

int main() {



	BTree<int> tree;
	BTNode<int> *r, *n1, *n2, *n3, *n4, *n5, *n6;
	r = new BTNode<int>;
	tree.insBinRoot(r);
	tree.write(r, 1);

	tree.insertSX(r);
	n1 = tree.sX(r);
	tree.write(n1, 3);

	tree.insertDX(r);
	n2 = tree.dX(r);
	tree.write(n2, 4);


	tree.insertSX(n1);
	n3 = tree.sX(n1);
	tree.write(n3, 8);

	tree.insertDX(n1);
	n4 = tree.dX(n1);
	tree.write(n4, 2);



	tree.insertDX(n2);
	n5 = tree.dX(n2);
	tree.write(n5, 6);




	/*
	int s = 0;
	int somma = tree.appello_3(tree.Root(), s);
	cout << "Appello 3: " << somma << endl;
	*/

	/*
	int u = 0;
	int updates = tree.appello_2(tree.Root(), u);
	cout << "Appello 2: " << updates << endl;
	*/

	/*
	List<BTNode<int>*> list = appello_1(tree);
	LNode<BTNode<int>*> *iter = new LNode<BTNode<int>*>;
	iter = list.begin();

	while(!list.endList(iter)){

		cout << list.read(iter)->value << endl;
		iter = list.succList(iter);

	}
	*/
	int u = 0;
	int updates = appello_2(tree, tree.Root(), u);
	cout << "Appello 2: " << updates << endl;

	return 0;
}


