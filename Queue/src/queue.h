/*
 * queue.h
 *
 *  Created on: 14 apr 2020
 *      Author: pc
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template<class T>
class Queue;

template<class T>
class QNode{
	friend class Queue<T>;
private:
	T value;
	QNode<T> *succ;
};

template<class T>
class Queue{
private:
	int lenght_;
	QNode<T> *top_;
	QNode<T> *tail;

public:
	Queue(){create();};
	Queue(const Queue &q);
	~Queue(){cleare();};
	void create();
	void cleare();
	bool empty();
	T top();
	void pop();
	void push(T);
	void printQueue();
	bool contains(T);
};

template<class T>
void Queue<T>::create(){
	lenght_ = 0;
	top_ = tail = nullptr;
}

template<class T>
void Queue<T>::cleare(){
	while(!empty())
	{
		pop();
	}
}

template<typename T>
Queue<T>::Queue(const Queue &q)
{
	create();

	QNode<T> *iter = q.top_;

	while(iter != nullptr)
	{
		push(iter->value);
		iter = iter->succ;
	}
}



template<class T>
bool Queue<T>::empty(){
	if(lenght_ == 0){
		return true;
	} else {
		return false;
	}
}

template<class T>
T Queue<T>::top(){
	return top_->value;
}

template<class T>
void Queue<T>::pop(){
	if(empty()){
		throw "queue empty!!";
	}
	QNode<T> *node = top_;

	top_ = top_->succ;
	delete node;

	lenght_--;
}

template<class T>
void Queue<T>::push(T v){
	QNode<T> *temp = new QNode<T>;
	temp->value = v;
	temp->succ = nullptr;

	if(empty()){
		top_ = tail = temp;

	} else {
		tail->succ = temp;
		tail = temp;
	}

	lenght_++;
}

template<class T>
bool Queue<T>::contains(T v){
	QNode<T> *iter = top_;
	QNode<T> *result;
	while(iter != nullptr){
		if(iter->value == v){
			result = iter;
		}
		iter = iter->succ;
	}

	if(result != nullptr){
		return true;
	} else {
		return false;
	}
}

template<class T>
void Queue<T>::printQueue(){
	QNode<T> *iter = top_;

	while(iter != nullptr){
		std::cout << iter->value << std::endl;
		iter = iter->succ;
	}
}



#endif /* QUEUE_H_ */
