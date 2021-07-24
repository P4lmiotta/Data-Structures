/*
 * stack.h
 *
 *  Created on: 14 apr 2020
 *      Author: pc
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template<class T>
class Stack;

template<class T>
class SNode {
	friend class Stack<T>;

private:
	T value;
	SNode* succ;
};

template<class T>
class Stack{
private:
	int size;
	SNode<T>* head;

public:

	Stack(){create();};
	~Stack(){cleare();};
	Stack(const Stack<T> &s);
	void create();
	void cleare();
	bool empty() const;
	T top();
	void pop();
	void push(T);
	void print_pila();
};

template<class T>
void Stack<T>::create(){
	size = 0;
	head = nullptr;
}

template<class T>
void Stack<T>::cleare(){
	while(!empty())
	{
		pop();
	}
}

template<class T>
Stack<T>::Stack(const Stack<T> &s){
	create();
	if(s.empty()){
		throw "stack is empty!";
	}
	SNode<T> *tmp1 = s.head;
	head = new SNode<T>;
	head->value = tmp1->value;
	head->succ = nullptr;
	tmp1 = tmp1->succ;
	SNode<T> *tmp2 = head;

	while(tmp1 != nullptr)
	{
		SNode<T> *node = new SNode<T>;
		node->value = tmp1->value;
		node->succ = nullptr;
		tmp2->succ = node;
		tmp1 = tmp1->succ;
		tmp2 = tmp2->succ;
	}
}

template<class T>
bool Stack<T>::empty() const{
	if(size == 0){
		return true;
	} else {
		return false;
	}
}

template<class T>
T Stack<T>::top(){
	return head->value;
}

template<class T>
void Stack<T>::pop(){
	SNode<T> *temp = head;
	head = head->succ;
	delete temp;

	size--;
}

template<class T>
void Stack<T>::push(T v){
	SNode<T> *temp = new SNode<T>;
	temp->value = v;

	temp->succ = head;
	head = temp;


	size++;
}

template<class T>
void Stack<T>::print_pila(){
	SNode<T> *iter = head;
	while(iter!= nullptr)
	{
		std::cout << iter->value <<std::endl;
		iter = iter->succ;
	}
}

#endif /* STACK_H_ */
