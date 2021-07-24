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
- With this structure, the search and modification operations of a dictionary can operate in constant and independent times both the size of the dictionary and the set of values that will be managed;
- Important is the hash function, that is a function that allows to avoid the problem of collisions (A collision occurs when different keys produce the same
result of the function). There are more or less good hash functions even if collisions can never be completely avoided; in this implementation the hash function is the following: 

  size_t hash_value = m_hash(k) % divisor, where the divisor is a number >= 1, and m_hash is a shift right operator the shifts k right 4 bits.
  
## N-ary Tree
A Tree is a widely used abstract data type that simulates a hierarchical tree structure, with a root value and child subtrees with a parent node, represented as a set of connected nodes.

A Tree can be recursively defined as a set of nodes (starting from a root node), where each node is a data structure consisting of a value, together with a list of references to the nodes (the "children"), where no references are duplicated and no one points to the root.

A node is a structure which may contain a value or condition, or represent a separate data structure (which could be a tree of its own). Each node in a tree has zero or more child nodes, which are below it in the tree (by convention, trees are drawn growing downwards). A node that has a child is called the child's parent node (or superior). Child nodes with the same parent are sibling nodes.

An internal node (also known as an inner node, inode for short, or branch node) is any node of a tree that has child nodes. Similarly, an external node (also known as an outer node, leaf node, or terminal node) is any node that does not have child nodes.

The topmost node in a tree is called the root node.

Here pre-order(DFS), post-order(DFS) and amplitude(BFS) visits are implemented.

## Binary Tree
A Binary Tree is a tree in which each node has at most two children and a distinction is made between the left child and the right child of a node.
A Binary Tree is equivalent to a N-ary Tree.

Here pre-visit(DFS), post-visit(DFS), simmetric-visit(DFS) and level-visit(BFS) visits are implemented.

## Search Binary Tree
Binary Search Tree is a node-based binary tree data structure which has the following properties:

- The left subtree of a node contains only nodes with keys lesser than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.

This data structure allows to implement the binary search of a Dictionary with better performances.

This means that it has the same operators as a Dictionary:
- Item lookup (Item k);
- insert (Item k, Item v);
- remove (Item k).
  
## Priority Queue
A Priority Queue is an extension of queue with following properties:

- Every item has a priority associated with it.
- An element with high priority is dequeued before an element with low priority.
- If two elements have the same priority, they are served according to their order in the queue.

For simplicity we make the priorities coincide with the elements themselves.

## Graph
The Graph is a structure composed of nodes and arcs that represents a binary relationship on the set consisting of nodes.
In general, nodes are used to represent objects and arcs to represent relationships between pairs of objects.

A Graph can be oriented, not-oriented, cyclic or acyclic (further the differences between them!).

Here is implemented IA search alghoritms like DFS, BFS, Iterative Deepining, Dijkstra and A* (further all of them!).
