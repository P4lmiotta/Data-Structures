/*
 * hash.h
 *
 *  Created on: 19 apr 2020
 *      Author: pc
 */

#ifndef HASH_H_
#define HASH_H_

#pragma once
#include <iostream>
#include <cstring>
#include "C:\Users\pc\Desktop\Strutture Dati\List\src\linked_list.h"

using namespace std;

template<class K>
class Hash
{
public:
	size_t operator()(K k) const{
		return (size_t)k >> 4;
	}
};

template <class K, class T>
class HashTable;

template<class K, class T>
class HTnode{
	friend class HashTable<K, T>;
public:
	K key;
	T value;
	HTnode *succ;
	HTnode *prec;

};

template <class K, class T>
class HashTable{
private:

	size_t HTsize;
	size_t divisor;
	HTnode<K, T> **table;
	Hash<K> m_hash;
public:

	void create(size_t);
	void cleare();

	T& operator[](K k);
	T operator[](K k) const;
	HashTable &operator=(const HashTable &ht);

	HashTable(int divisor){create(divisor);};
	~HashTable(){
		cleare();
		delete[] table;
	};
	bool isEmpty() const;
	bool appartiene(K) const;
	void inserisci(K, T);
	void erase(K);
	void remove(K);
	T recupera(K) const;
	HTnode<K, T> *ricerca(K, size_t) const;
	List<K> keys() const;
	size_t _divisor() const{
		return divisor;
	}
	void printValue(K k);

	template<class U, class V>
	friend std::ostream &operator<<(std::ostream &os, const HashTable<U, V> &ht);
};

template<class K, class T>
void HashTable<K, T>::create(size_t divisore){
	divisor = divisore;
	if(divisor == 0){
		divisor = 1;
	}
	HTsize = 0;
	table = new HTnode<K, T> *[divisor];
	for(size_t i = 0; i < divisor; i++){
		table[i] = nullptr;
	}
}

template<class K, class T>
void HashTable<K,T>::cleare(){
	for(size_t i = 0; i < divisor; i++)
	{
		HTnode<K, T> *temp = table[i];

		while(temp != nullptr)
		{
			HTnode<K, T> *node = temp;
			temp = temp->succ;
			delete node;
		}
	}

	HTsize = 0;

}

template<class K, class T>
bool HashTable<K,T>::isEmpty() const{
	if(HTsize == 0)
		return true;
	else
		return false;
}

template<class K, class T>
T HashTable<K, T>::recupera(K k) const{
	size_t h = m_hash(k) % divisor;
	HTnode<K, T> *found = ricerca(k, h);
	if(found == nullptr)
		throw "element not found";
	else
		return found->value;
}



template<typename K, typename T>
void HashTable<K, T>::inserisci(K k, T v) {
	size_t h = m_hash(k) % divisor;
	HTnode<K, T> *found = ricerca(k, h);
	if(found == nullptr){
		HTnode<K, T> *temp = new HTnode<K, T>;
		temp->key = k;
		temp->value = v;
		temp->succ = table[h];
		temp->prec = nullptr;
		if(table[h] != nullptr){
			table[h]->prec = temp;
		}
		table[h] = temp;
		HTsize++;

	} else {
		found->value = v;
	}
}

template<class K, class T>
HTnode<K, T> *HashTable<K, T>::ricerca(K k, size_t h) const{
	HTnode<K, T> *found = table[h];
	while(found != nullptr){
		if(found->key == k){
			return found;
		}
		found = found->succ;
	}
	return nullptr;
}

template<class K, class T>
bool HashTable<K,T>::appartiene(K k) const{
	size_t h = m_hash(k) % divisor;
	HTnode<K, T> *node = ricerca(k, h);
	return node!=nullptr;
}

template<class K, class T>
void HashTable<K, T>::printValue(K k){
	size_t h = m_hash(k) % divisor;
	HTnode<K, T> *iter = table[h];
	while(iter != nullptr){
		std::cout<< iter->value << std::endl;
		iter = iter->succ;
	}
}

template<class K, class T>
void HashTable<K, T>::remove(K k){
	size_t h = m_hash(k) % divisor;

	HTnode<K, T> *node = ricerca(k, h);

	if(node == nullptr)
		throw "element not found";

	if(node->prec != nullptr)
		node->prec->succ = node->succ;
	else
		table[h] = node->succ;

	if(node->succ != nullptr)
		node->succ->prec = node->prec;

	delete node;

	HTsize--;
}

template<class K, class T>
List<K> HashTable<K, T>::keys() const{
	List<K> keys;
	for(size_t i = 0; i < divisor; i++)
	{
		HTnode<K, T> *temp = table[i];

		while(temp != nullptr)
		{
			keys.pushBack(temp->key);

			temp = temp->succ;
		}
	}

	return keys;
}

template<typename K, typename T>
T& HashTable<K, T>::operator[](K k)
{
	size_t h = m_hash(k) % divisor;

	HTnode<K, T> *e = ricerca(k, h);

	if(e == nullptr)
		throw "element not found";

	return e->value;
}

template<typename K, typename T>
T HashTable<K, T>::operator[](K k) const
{
	return recupera(k);
}

template<class K, class T>
std::ostream &operator<<(std::ostream &os, const HashTable<K, T> &ht)
{
	for(size_t i = 0; i <ht._divisor(); i++)
	{
		os << i << ") [ ";

		HTnode<K, T> *tmp = ht.table[i];

		while(tmp != nullptr)
		{
			os << "(" << tmp->key << " " << tmp->value << ") ";

			tmp = tmp->succ;
		}

		os << "]" << std::endl;
	}

	return os;
}

template<typename K, typename T>
HashTable<K, T> &HashTable<K, T>::operator=(const HashTable<K, T> &ht)
{
	if(this == &ht)
		return *this;

	if(!isEmpty())
	{
		cleare();
		delete [] table;
	}

	divisor = ht.divisor;

	table = new HTnode<K, T>*[divisor];

	for(size_t i = 0; i < ht.divisor; i++)
	{
		HTnode<K, T> *tmp = ht.table[i];

		while(tmp != nullptr)
		{
			insert(tmp->key, tmp->value);

			tmp = tmp->succ;
		}
	}

	return *this;
}


#endif /* HASH_H_ */
