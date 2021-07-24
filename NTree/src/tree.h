/*
 * tree.h
 *
 *  Created on: 14 apr 2020
 *      Author: Alessandro Palmiotta
 */

#ifndef TREE_H_
#define TREE_H_

#include "List\src\linked_list.h"
#include "Queue\src\queue.h"
#include "iostream"

template<class T>
class Tree;

template<class T>
class TNode {
	friend class Tree<T>;

private:
	T value;
	TNode<T>* parent = nullptr;
	List<TNode<T> *> childs;
};

template<class T>
class Tree {
private:
	TNode<T> *root;
	int size;

public:
	void create();
	void cleare();
	void copy(TNode<T>*); // da aggiustare
	Tree(){create();};
	~Tree(){cleare();};
	Tree(const Tree<T> &);
	bool empty();
	void insRoot(T);
	TNode<T>* Root() const;
	TNode<T>* Parent(TNode<T>*);
	bool isLeaf(TNode<T>*);
	TNode<T>* firstChild(TNode<T>*);
	bool lastBrother(TNode<T>*) const;
	TNode<T>* succBrother(TNode<T>*);
	void insFirstUnderTree(TNode<T>*);
	void insUnderTree(TNode<T>*);
	TNode<T>* insertNodeChild(TNode<T>*, T);
	void eraseUnderTree(TNode<T>*);
	void write(TNode<T>*, T);
	T read(TNode<T>*);
	void preOrder(TNode<T>*); //DFS preOrdine
	void postOrder(TNode<T>*); //DFS postOrdine
	void levelVisit(); //BFS

};

template<class T>
void Tree<T>::create(){
	root = nullptr;
	size = 0;
}

template<class T>
void Tree<T>::cleare(){
	eraseUnderTree(Root());
}

template<class T>
void Tree<T>::copy(TNode<T>* p){

	Queue<TNode<T>*> queue;
	queue.push(p);
	while(!queue.empty())
	{
		TNode<T>* n = new TNode<T>;
		TNode<T>* node = queue.top();
		n->value = p->value;
		queue.pop();
		const List<TNode<T> *> &ch = node->childs;
		LNode<TNode<T> *> *temp = ch.begin();
		while(!ch.endList(temp))
		{
			queue.push(ch.read(temp));
			temp = ch.succList(temp);
		}
	}
	size++;


}

template<class T>
Tree<T>::Tree(const Tree<T> &t){
	size = 0;
	create();
	copy(t.Root());
}

template<class T>
bool Tree<T>::empty(){
	if(size == 0){
		return true;
	} else {
		return false;
	}
}

template<class T>
void Tree<T>::insRoot(T value){
	root = new TNode<T>;
	root->value = value;
	root->parent = nullptr;
	size++;
}

template<class T>
TNode<T>* Tree<T>::Root() const{
	return root;
}

template<class T>
TNode<T>* Tree<T>::Parent(TNode<T>* node){
	return node->parent;
}

template<class T>
bool Tree<T>::isLeaf(TNode<T>* node){
	if(node->childs.empty()){
		return true;
	} else {
		return false;
	}
}

template<class T>
TNode<T>* Tree<T>::firstChild(TNode<T>* node){
	return node->childs.read(node->childs.begin());
}

template<class T>
bool Tree<T>::lastBrother(TNode<T>* node) const{
	LNode<TNode<T> *> *temp = new LNode<TNode<T> *>;
	temp = node->parent->childs.find(node);
	if(node->parent->childs.endList(temp)){
		return true;
	} else {
		return false;
	}
}

template<class T>
void Tree<T>::write(TNode<T>* node, T value){
	node->value = value;
}

template<class T>
T Tree<T>::read(TNode<T>* node){
	return node->value;
}

template<class T>
TNode<T>* Tree<T>::succBrother(TNode<T>* node){
	LNode<TNode<T> *>* temp;
	temp = node->parent->childs.find(node);
	temp = node->parent->childs.succList(temp);
	return node->parent->childs.read(temp);
}

template<class T>
void Tree<T>::insFirstUnderTree(TNode<T>* node){
	node->parent = root;
	root->childs.pushFront(node);

	size++;
}



template<class T>
void Tree<T>::insUnderTree(TNode<T>* node){
	root->childs.pushBack(node);
	node->parent = root;
	size++;
}

template<class T>
TNode<T>* Tree<T>::insertNodeChild(TNode<T>* parent, T value){
	TNode<T>* temp = new TNode<T>;
	temp->value = value;
	temp->parent = parent;
	parent->childs.pushBack(temp);

	size++;
	return temp;
}

template<class T>
void Tree<T>::eraseUnderTree(TNode<T>* node){
	if(node == nullptr){
		throw "Tree doesn't exist!!";
	} else {
		LNode<TNode<T> *> *temp;
		if(!isLeaf(node)){
			const List<TNode<T> *> &ch = node->childs;
			temp = ch.begin();
			while(!ch.endList(temp))
			{
				eraseUnderTree(ch.read(temp));
				temp = ch.succList(temp);
			}
		}

		delete node;
		size--;
	}

}

template<class T>
void Tree<T>::preOrder(TNode<T>* node){
	std::cout<< node->value << std::endl;
	const List<TNode<T> *> &ch = node->childs;
	LNode<TNode<T> *> *temp = ch.begin();
	while(!ch.endList(temp))
	{
		preOrder(ch.read(temp));
		temp = ch.succList(temp);
	}
}

template<class T>
void Tree<T>::postOrder(TNode<T>* node){
	const List<TNode<T> *> &ch = node->childs;
	LNode<TNode<T> *> *temp = ch.begin();
	while(!ch.endList(temp))
		{
			postOrder(ch.read(temp));
			temp = ch.succList(temp);
		}
	std::cout<< node->value << std::endl;
}

template<class T>
void Tree<T>::levelVisit(){
	Queue<TNode<T>*> queue;
	queue.push(Root());
	while(!queue.empty())
	{
		TNode<T>* node = queue.top();
		std::cout<< node->value << std::endl;
		queue.pop();
		if(!isLeaf(node)){
			const List<TNode<T> *> &ch = node->childs;
			LNode<TNode<T> *> *temp = ch.begin();
			while(!ch.endList(temp))
			{
				queue.push(ch.read(temp));
				temp = ch.succList(temp);
			}
		}
	}
}





#endif /* TREE_H_ */
