/*
 * searchbinarytree.h
 *
 *  Created on: 16 apr 2020
 *      Author: pc
 */

#ifndef SEARCHBINARYTREE_H_
#define SEARCHBINARYTREE_H_

#include <iostream>

template<class T, class K>
class SBTree;

template<class T, class K>
class SBTNode{
	friend class SBTree<T, K>;
private:
	T value;
	K key;
	SBTNode<T, K> *parent;
	SBTNode<T, K> *sx;
	SBTNode<T, K> *dx;


};

template<class T, class K>
class SBTree{
private:
	SBTNode<T, K> *root;
	int size;

public:
	void create();
	SBTree(){create();};

	void cleare(SBTNode<T, K> *);
	~SBTree(){cleare(Root());};

	K Key(SBTNode<T, K> *);
	T Value(SBTNode<T, K> *);
	SBTNode<T, K> * left(SBTNode<T, K> *);
	SBTNode<T, K> * right(SBTNode<T, K> *);
	SBTNode<T, K> * Parent(SBTNode<T, K> *);
	bool emptyLeft(SBTNode<T, K> *);
	bool emptyRight(SBTNode<T, K> *);
	SBTNode<T, K> * Root();
	SBTNode<T, K> * lookupNode(SBTNode<T, K> *, K);
	bool contains(SBTNode<T, K> *, K);
	void link(SBTNode<T, K> *, SBTNode<T, K> *, K);
	SBTNode<T, K> * insertNode(K, T);
	void removeNode(SBTNode<T, K> *, K);
	SBTNode<T, K> * min(SBTNode<T, K> *);
	SBTNode<T, K> * max(SBTNode<T, K> *);
	void simmetricVisit(SBTNode<T, K> *);
};

template<class T, class K>
void SBTree<T, K>::create(){
	root = nullptr;
	size = 0;
}

template<class T, class K>
void SBTree<T, K>::cleare(SBTNode<T, K> * node){
	if(node == nullptr){
		return;
	}
	cleare(left(node));
	node->sx = nullptr;
	cleare(right(node));
	node->dx = nullptr;
	delete node;
	size--;


}

template<class T, class K>
K SBTree<T, K>::Key(SBTNode<T, K> *node){
	return node->key;
}

template<class T, class K>
T SBTree<T, K>::Value(SBTNode<T, K> *node){
	return node->value;
}

template<class T, class K>
SBTNode<T, K> * SBTree<T, K>::left(SBTNode<T, K> *node){
	return node->sx;
}

template<class T, class K>
SBTNode<T, K> * SBTree<T, K>::right(SBTNode<T, K> *node){
	return node->dx;
}

template<class T, class K>
SBTNode<T, K> * SBTree<T, K>::Parent(SBTNode<T, K> *node){
	return node->parent;
}

template<class T, class K>
bool SBTree<T, K>::emptyLeft(SBTNode<T, K> *node){
	if(left(node) == nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T, class K>
bool SBTree<T, K>::emptyRight(SBTNode<T, K> *node){
	if(right(node) == nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T, class K>
SBTNode<T, K> * SBTree<T, K>::Root(){
	return root;
}

template<class T, class K>
SBTNode<T, K> * SBTree<T, K>::lookupNode(SBTNode<T, K> *node, K k){
	while((node != nullptr) && (node->key != k))
	{
		if(k < node->key){
			node = node->sx;
		} else {
			node = node->dx;
		}
	}
	return node;
}

template<class T, class K>
bool SBTree<T, K>::contains(SBTNode<T, K> *node, K k){
	if(lookupNode(node, k) != nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T, class K>
void SBTree<T, K>::link(SBTNode<T, K> *p, SBTNode<T, K> *node, K k){
		if(k < p->key){
			p->sx = node;
		} else {
			p->dx = node;
		}
}

template<class T, class K>
SBTNode<T, K> * SBTree<T, K>::insertNode(K k, T v){
	SBTNode<T, K> * node = new SBTNode<T, K>;
	node->value = v;
	node->key = k;
	node->sx = nullptr;
	node->dx = nullptr;

	SBTNode<T, K> *p = nullptr;
	SBTNode<T, K> *temp = Root();

	while((temp != nullptr) && (temp->key != k))
	{
		p = temp;
		if(k < temp->key){
			temp = temp->sx;
		} else {
			temp = temp->dx;
		}
	}

	node->parent = p;

	if(p == nullptr){
		root = node;
	} else {
		link(p, node, k);
	}
	size++;
	return node;
}

template<class T, class K>
void SBTree<T, K>::removeNode(SBTNode<T, K> *node, K k){
	SBTNode<T, K> *temp = lookupNode(node, k);
	if(node == nullptr){
		throw "Node doesn't exist in tree!!!";
	} else {
		if((!emptyLeft(temp)) && (!emptyRight(temp))){
			SBTNode<T, K> *s = right(temp);
			while(!emptyLeft(s))
			{
				s = left(s);
			}
			temp->key = s->key;
			temp->value = s->value;
			temp = s;
		}
		SBTNode<T, K> *t;
		if((!emptyLeft(temp)) && (emptyRight(temp))){
			t = left(temp);
		} else {
			t = right(temp);
		}
		if(t != nullptr){
			t->parent = temp->parent;
		}
		if(temp->parent != nullptr){
			link(temp->parent, t, k);
		}
		if(temp->parent == nullptr){
			node = t;
		}
		delete temp;
		size--;
	}
}

template<class T, class K>
SBTNode<T, K> * SBTree<T,K>::min(SBTNode<T, K> *node){
	while(left(node) != nullptr){
		node = left(node);
	}
	return node;
}

template<class T, class K>
SBTNode<T, K> * SBTree<T,K>::max(SBTNode<T, K> *node){
	while(right(node) != nullptr){
		node = right(node);
	}
	return node;
}

template<class T, class K>
void SBTree<T, K>::simmetricVisit(SBTNode<T, K> *node){
	if(!emptyLeft(node)){
		simmetricVisit(left(node));
	}

	std::cout << "Key: " << Key(node) << " - " << "Value: " << Value(node) << std::endl;

	if(!emptyRight(node)){
		simmetricVisit(right(node));
	}
}



#endif /* SEARCHBINARYTREE_H_ */
