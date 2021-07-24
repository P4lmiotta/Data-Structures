/*
 * prioritycode.h
 *
 *  Created on: 17 apr 2020
 *      Author: Alessandro Palmiotta
 */

#ifndef PRIORITYCODE_H_
#define PRIORITYCODE_H_

#include <iostream>
#include "assert.h"
#include <cstddef>
#include <cstring>

template<class T>
class PriorityCode{
private:
	T *heap;
	size_t dimension;
	size_t last;
	void fixUp();
	void fixDown();

public:
	PriorityCode(){create();};
	PriorityCode(size_t);
	~PriorityCode();

	PriorityCode &operator=(const PriorityCode &q);

	void create();
	bool empty() const;
	void inserisci(T);
	T min() const;
	T& min();
	void cancellaMin();
	bool appartiene(T) const;
	void print();
};

template<class T>
void PriorityCode<T>::create(){
	dimension = 100;
	heap = new T[dimension];
	last = 0;
}

template<class T>
bool PriorityCode<T>::empty() const{
	if(last == 0)
		return true;
	else
		return false;
}

template<class T>
PriorityCode<T>::PriorityCode(size_t dimension_){
	dimension = dimension_;
	heap = new T[dimension];
	last = 0;
}

template<class T>
PriorityCode<T>::~PriorityCode(){
	delete[] heap;
}

template<class T>
void PriorityCode<T>::inserisci(T element){
	assert(last < dimension);
	heap[++last - 1] = element;
	fixUp();
}

template<class T>
T PriorityCode<T>::min() const{
	assert(last != 0);
	return heap[0];
}

template<class T>
void PriorityCode<T>::cancellaMin(){
	assert(last != 0);
	heap[0] = heap[last - 1];
	last--;
	fixDown();
}

template<class T>
bool PriorityCode<T>::appartiene(T element) const{
	for(size_t i = 0; i < last; i++){
		if(heap[i] == element){
			return true;
		}
	}
	return false;
}

template<class T>
void PriorityCode<T>::fixUp(){
	size_t i = last - 1;

	while(i != 0 && heap[i] < heap[i / 2])
	{
		T tmp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = tmp;
		i /= 2;
	}
}

template<class T>
void PriorityCode<T>::fixDown(){
	size_t i = 0;

	while(i < last / 2)
	{
		size_t j = 2 * i;

		if(j < last && heap[j + 1] < heap[j])
			j++;

		if(heap[j] < heap[i])
		{
			T tmp = heap[i];
			heap[i] = heap[j];
			heap[j] = tmp;
			i = j;
		}
		else
		{
			break;
		}
	}
}

template<class T>
void PriorityCode<T>::print(){
	std::cout << "[";
	for(size_t i = 0; i < last; i++){
		std::cout << heap[i] << " ";
	}
	std::cout << "]" << std::endl;
}

template<typename T>
PriorityCode<T>& PriorityCode<T>::operator=(const PriorityCode<T> &q)
{
	if(this == &q)
		return *this;

	last = 0;

	delete [] heap;
	heap = new T[q.dimension];
	dimension = q.dimension;
	last = q.last;

	for(size_t i = 0; i < last; i++)
		heap[i] = q.heap[i];

	return *this;
}

template<typename T>
T& PriorityCode<T>::min()
{
	if(empty())
		throw "heap is empty";

	return heap[0];
}



#endif /* PRIORITYCODE_H_ */
