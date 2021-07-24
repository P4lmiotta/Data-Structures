# Data-Structures C++
This is a repository of data structures written in C++.
This repo provides the basic requirements to understand and implement these data structures using any language of your choosing.
The data structures are written in C++ because for me this language has been my first OOP language and I started learn data structures with it.

Here is the list of data structures:
- Double Linked List;
- Stack;
- Queue;
- HashTable;
- N-ary Tree;
- Binary Tree;
- Search Binary Tree;
- Priority Queue;
- Graph.

## Double Linked List
A List is a sequence of elements, even empty, of the same type.

Each element of a list has its own position and its own value, and can only be accessed sequentially, by scrolling through all the elements that precede it.

The implemented List is a Double Linked List, that is a list that starts from the head element and ends at the tail element, where each element (node) points to the previous element and to the next element.

Finally, creation, update (insert), search (read), delete operators are implemented.

## Stack
A Stack is a sequence of elements that follows a LIFO (Last In First Out) approach.

In a Stack we remove the item the most recently added.

The insert and delete operators turn into push () and pop () operators, respectively.

## Queue
A Queue is a sequence of elements that follows a FIFO (First In First Out) approach, unlike the Stack.

In a Queue we remove the item the least recently added.

The insert and delete operators turn into push () and pop () operators, respectively.

## HashTable
An Hash Table is a data structure used to match a given key with a given value. 

Elements are generally structured types to which accesses by means of a reference to a key field. The elements take the form of a pair consisting of (key, value).

It is a Dictionary (subset of the Set data structure) that rests on
a tabular data structure:
- With this structure, the search and modification operations of a dictionary can operate in constant and independent times both the size of the dictionary and the set of values that will be managed
- Important is the hash function, that is a function that allows to avoid the problem of collisions (A collision occurs when different keys produce the same
result of the function). There are more or less good hash functions even if collisions can never be completely avoided; in this implementation the hash function is the following: 

  size_t hash_value = m_hash(k) % divisor, where the divisor is a number >= 1, and m_hash is a shift right operator the shifts k right 4 bits
  

