/*
 * binarytree.h
 *
 *  Created on: 15 apr 2020
 *      Author: pc
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
#include "C:\Users\pc\Desktop\Strutture Dati\Queue\src\queue.h"
#include "C:\Users\pc\Desktop\Strutture Dati\List\src\linked_list.h"

template<class T>
class BTree;

template<class T>
class BTNode{
	friend class BTree<T>;
public:
	T value;
private:
	BTNode<T>* parent;
	BTNode<T>* sx;
	BTNode<T>* dx;
};

template<class T>
class BTree{
private:
	BTNode<T>* root;
	int size;

public:
	//Costruttore

	BTree(){create();};

	//Costruttore di copia
	BTree(const BTree<T> &tree){
		size = 0;
		root = copy(tree.Root(), nullptr);
	}

	//Distruttore

	~BTree(){
		eraseSubTree(Root());
	};

	//Metodi
	void create();
	BTNode<T>* copy(BTNode<T>*, BTNode<T>*);
	void eraseSubTree(BTNode<T>*);
	bool empty();
	BTNode<T>* Root() const;
	void insBinRoot(BTNode<T>*);
	BTNode<T>* parent(BTNode<T>*);
	BTNode<T>* sX(BTNode<T>*);
	BTNode<T>* dX(BTNode<T>*);
	bool emptySX(BTNode<T>*);
	bool emptyDX(BTNode<T>*);
	void insertSX(BTNode<T>*);
	void insertDX(BTNode<T>*);
	T read(BTNode<T>*);
	void write(BTNode<T>*, T);

	//Visite
	void simmetricVisit(BTNode<T>*); //DFS
	void preVisit(BTNode<T>*); //DFS
	void postVisit(BTNode<T>*); //DFS
	void levelVisit(BTNode<T>*); //BFS

	void Visit_appello_1(BTNode<T>* node, List<BTNode<T>*> &list ); //visita appello 1
	T appello_3(BTNode<T>* node, T somma);
	int appello_2(BTNode<T>* node, int updates);

};

template<class T>
void BTree<T>::create(){
	root = nullptr;
	size = 0;
}

template<class T>
bool BTree<T>::empty(){
	if(size == 0){
		return true;
	} else {
		return false;
	}
}

template<class T>
BTNode<T>* BTree<T>::Root() const{
	return root;
}

template<class T>
void BTree<T>::insBinRoot(BTNode<T>* node){
	root = new BTNode<T>;
	root = node;
	root->parent = nullptr;
	root->sx = nullptr;
	root->dx = nullptr;
	size++;
}

template<class T>
BTNode<T>* BTree<T>::parent(BTNode<T>* node){
	return node->parent;
}

template<class T>
BTNode<T>* BTree<T>::sX(BTNode<T>* node){
	return node->sx;
}

template<class T>
BTNode<T>* BTree<T>::dX(BTNode<T>* node){
	return node->dx;
}

template<class T>
bool BTree<T>::emptySX(BTNode<T>* node){
	if(sX(node) == nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T>
bool BTree<T>::emptyDX(BTNode<T>* node){
	if(dX(node) == nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T>
void BTree<T>::insertSX(BTNode<T>* node){
	BTNode<T>* temp = new BTNode<T>;
	temp->parent = node;
	temp->sx = nullptr;
	temp->dx = nullptr;
	node->sx = temp;

	size++;
}

template<class T>
void BTree<T>::insertDX(BTNode<T>* node){
	BTNode<T>* temp = new BTNode<T>;
	temp->parent = node;
	temp->sx = nullptr;
	temp->dx = nullptr;
	node->dx = temp;

	size++;
}

template<class T>
T BTree<T>::read(BTNode<T>* node){
	return node->value;
}

template<class T>
void BTree<T>::write(BTNode<T>* node, T value){
	node->value = value;
}

template<class T>
void BTree<T>::simmetricVisit(BTNode<T>* node){
	if(!emptySX(node)){
		simmetricVisit(sX(node));
	}

	std::cout << node->value << std::endl;

	if(!emptyDX(node)){
		simmetricVisit(dX(node));
	}
}

template<class T>
void BTree<T>::preVisit(BTNode<T>* node){
	std::cout << node->value << std::endl;

	if(!emptySX(node)){
		preVisit(sX(node));
	}

	if(!emptyDX(node)){
		preVisit(dX(node));
	}
}

template<class T>
void BTree<T>::postVisit(BTNode<T>* node){
	if(!emptySX(node)){
		postVisit(sX(node));
	}

	if(!emptyDX(node)){
		postVisit(dX(node));
	}

	std::cout << node->value << std::endl;
}

template<class T>
void BTree<T>::levelVisit(BTNode<T>* node){
	Queue<BTNode<T>*> queue;
	queue.push(node);
	while(!queue.empty())
	{
		BTNode<T>* temp = queue.top();
		if(temp != nullptr){
			std::cout << read(temp) << std::endl;
		}
		queue.pop();
		if(!emptySX(temp)){
			queue.push(sX(temp));
		}
		if(!emptyDX(temp)){
			queue.push(dX(temp));
		}
	}
}

template<class T>
void BTree<T>::eraseSubTree(BTNode<T>* node){

	if(node != nullptr){
		eraseSubTree(sX(node));
		eraseSubTree(dX(node));

		delete node;
		size--;
	}

}

template<class T>
BTNode<T>* BTree<T>::copy(BTNode<T> *node, BTNode<T> *parent)
{
	if(node == nullptr){
		return nullptr;
	}
	BTNode<T> *temp = new BTNode<T>;
	temp->value = node->value;
	temp->parent = parent;
	temp->sx = _copy(node->sx, temp);
	temp->dx = _copy(node->dx, temp);
	size++;

	return node;
}

template<class T>
List<BTNode<T>*> appello_1( BTree<T> &tree){
	List<BTNode<T>*> list;

	tree.Visit_appello_1(tree.Root(), list);

	return list;

}

template<class T>
T BTree<T>::appello_3(BTNode<T>* node, T somma){

	T value = this->read(node);
	std::cout << value << std::endl;

	if(value%2 == 0){
		value++;
	}
	somma += value;
	if(!this->emptySX(node)){

		somma = appello_3(this->sX(node), somma);

	}

	if(!this->emptyDX(node)){

		somma = appello_3(this->dX(node), somma);

	}

	return somma;

}

template<class T>
int BTree<T>::appello_2(BTNode<T>* node, int updates){

	if(!this->emptySX(node)){
		updates = appello_2(this->sX(node), updates);
	}

	T value = this->read(node);
	std::cout << value << std::endl;
	if(value%2 != 0){
		std::cout << "Valore dispari: "<< value << std::endl;
		value = value + 1;
		std::cout << "Valore aggiornato: "<< value << std::endl;
		updates++;
	}

	if(!this->emptyDX(node)){
		updates = appello_2(this->dX(node), updates);
	}

	return updates;

}
template<class T>
int appello_2( BTree<T> &tree, BTNode<T>* node, int updates){
	if(!tree.emptySX(node)){
		updates = appello_2(tree, tree.sX(node), updates);
	}

	T value = tree.read(node);
	std::cout << value << std::endl;
	if(value%2 != 0){
		std::cout << "Valore dispari: "<< value << std::endl;
		value = value + 1;
		std::cout << "Valore aggiornato: "<< value << std::endl;
		updates++;
	}

	if(!tree.emptyDX(node)){
		updates = appello_2(tree, tree.dX(node), updates);
	}

	return updates;
}

template<class T>
void BTree<T>::Visit_appello_1(BTNode<T>* node, List<BTNode<T>*> &list){

	if(!emptySX(node)){
		Visit_appello_1(sX(node), list);
	}


	if(node->value%2 == 0){
		list.pushBack(node);
	}


	if(!emptyDX(node)){
		Visit_appello_1(dX(node), list);
	}


}


#endif /* BINARYTREE_H_ */
