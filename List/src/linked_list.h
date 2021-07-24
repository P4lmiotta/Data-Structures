/*
 * linked_list.h
 *
 *  Created on: 17 apr 2020
 *      Author: Alessandro Palmiotta
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>


template<class T>
class List;

template<class T>
class LNode {
	friend class List<T>;
private:
	T value;
	LNode* succ;
	LNode* prec;
public:
	T getValue(){
		return value;
	}
};

template<class T>
class List {

private:
	LNode<T>* head;
	LNode<T>* tail;
	size_t size;

public:
	void create();
	void clear();
	List(){create();};
	List(const List &l);
	~List(){clear();};

	bool empty() const;
	LNode<T>* begin() const;
	LNode<T>* end() const;
	LNode<T>* succList(LNode<T>*) const;
	LNode<T>* precList(LNode<T>*) const;
	bool endList(LNode<T>*) const;
	T read(LNode<T>*) const;
	void write(LNode<T>*, T);
	int Size();
	void insert(LNode<T>*, T);
	void erase(LNode<T>*);
	void printList();
	void pushFront(T);
	void pushBack(T);
	LNode<T>* find(T) const;
};

template<class T>
void List<T>::create(){
	size = 0;
	head = tail = nullptr;
}
template<class T>
void List<T>::clear(){
	LNode<T>* iter = new LNode<T>;
	while(head != nullptr)
	{
		iter = head;
		head = head->succ;
		delete iter;
	}
}

template<class T>
List<T>::List(const List<T> &l){
	create();
	LNode<T> *temp = l.begin();

	while(!l.endList(temp))
	{
		pushBack(temp->value);
		temp = temp->succ;
	}
}

template<class T>
bool List<T>::empty() const{
	if(head == nullptr) {
		return true;
	} else {
		return false;
	}
}

template<class T>
LNode<T>* List<T>::begin() const{
	return head;
}

template<class T>
LNode<T>* List<T>::end() const{
	return tail;
}

template<class T>
LNode<T>* List<T>::succList(LNode<T>* node) const{
	return node->succ;
}

template<class T>
LNode<T>* List<T>::precList(LNode<T>* node) const{
	return node->prec;
}

template<class T>
bool List<T>::endList(LNode<T>* node) const{
	if(node == nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T>
T List<T>::read(LNode<T>* node) const{
	return node->value;
}

template<class T>
void List<T>::write(LNode<T>* node, T value){
	node->value = value;
}

template<class T>
int List<T>::Size(){
	return size;
}

template<class T>
void List<T>::insert(LNode<T>* node, T value){
	LNode<T>* temp = new LNode<T>;
	temp->value = value;
	temp->succ = node->succ;
	temp->prec = node;

	if(node->succ == nullptr){
		tail = temp;
	} else {
		node->succ->prec = temp;
	}
	node->succ = temp;
	size++;
}

template<class T>
void List<T>::pushFront(T value){
	LNode<T> *node = new LNode<T>;
	node->value = value;
	node->prec = nullptr;

	if(empty())
	{
		tail = node;
		node->succ = nullptr;
	}
	else
	{
		head->prec = node;
		node->succ = head;
	}

	head = node;

	size++;
}

template<class T>
void List<T>::pushBack(T value){
	LNode<T> *node = new LNode<T>;
	node->value = value;
	node->succ = nullptr;

	if(empty())
	{
		head = node;
		node->prec = nullptr;
	}
	else
	{
		tail->succ = node;
		node->prec = tail;
	}

	tail = node;

	size++;
}

template<class T>
void List<T>::erase(LNode<T>* node){
	LNode<T>* temp = new LNode<T>;
	temp = node;
	if(node != nullptr){
		if(size == 1){
			head = tail = nullptr;
		}

		if(node->prec == nullptr){

			head = node->succ;
		} else {
			node->prec->succ = node->succ;
		}

		if(node->succ == nullptr) {
			tail = node->prec;
		} else {
			node->succ->prec = node->prec;
		}
	}

	delete temp;
	size--;

}

template<class T>
LNode<T>* List<T>::find(T value) const{
	LNode<T>* iter = new LNode<T>;
	iter = begin();


	while(!endList(iter))
	{
		if(iter->value == value){
			return iter;
		}
		iter = succList(iter);
	}
	return nullptr;
}

template<class T>
void List<T>::printList(){
	LNode<T>* iter = new LNode<T>;
	iter = begin();

	while(!endList(iter))
	{
		std::cout<< read(iter) << std::endl;
		iter = succList(iter);
	}
}

#endif /* LINKED_LIST_H_ */
