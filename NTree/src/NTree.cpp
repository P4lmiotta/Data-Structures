//============================================================================
// Name        : NTree.cpp
// Author      : Alessandro Palmiotta
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "tree.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Tree<int> tree;
	Tree<int> tree1;
	Tree<int> tree2;
	Tree<int> tree3;
	TNode<int> *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10;
	n1 = new TNode<int>;
	n2 = new TNode<int>;
	n3 = new TNode<int>;
	n4 = new TNode<int>;
	n5 = new TNode<int>;
	n6 = new TNode<int>;
	n7 = new TNode<int>;
	n8 = new TNode<int>;
	n9 = new TNode<int>;
	n10 = new TNode<int>;


	tree.insRoot(1);

	tree.write(n1, 4);
	tree.write(n2, 15);
	tree.write(n3, 6);
	tree.write(n4, 5);
	tree.write(n5, 6);
	tree.write(n6, 7);
	tree.write(n7, 8);
	tree.write(n8, 9);
	tree.write(n9, 10);
	tree.write(n10, 11);



	tree.insUnderTree(n1);
	tree.insUnderTree(n2);
	tree.insUnderTree(n3);

	tree1.insRoot(10);
	tree1.insUnderTree(n4);
	tree1.insUnderTree(n5);
	tree1.insUnderTree(n6);

	//tree.insUnderTree(tree1.Root());

	//tree.preOrder(tree.Root());
	tree.levelVisit();



	//tree.preVisit(tree.Root());sb
	cout<<"---------------"<<endl;

	tree2.insRoot(5);
	tree2.insUnderTree(n1);
	tree2.insUnderTree(n2);
	tree2.insUnderTree(n3);
	n4 = tree2.insertNodeChild(n1, 8);
	n5 = tree2.insertNodeChild(n1, 9);
	n6 = tree2.insertNodeChild(n5, 12);
	n7 = tree2.insertNodeChild(n5, 11);
	n10 = tree2.insertNodeChild(n5, 3);
	n8 = tree2.insertNodeChild(n3, 21);
	n9 = tree2.insertNodeChild(n3, 20);

	//tree2.preOrder(tree2.Root());
	cout<<"---------------"<<endl;
	//tree2.postOrder(tree2.Root());
	cout<<"---------------"<<endl;
	cout<<"---------------"<<endl;
	cout<<"---------------"<<endl;
	tree2.levelVisit();

	tree3 = tree;
	tree3.eraseUnderTree(n4);
	cout<<"---------------"<<endl;
	tree3.levelVisit();


	//tree.preVisit(n3);
	//tree.postVisit(tree.Root());
	return 0;
}
