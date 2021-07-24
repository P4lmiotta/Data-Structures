//============================================================================
// Name        : Graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "graph.h"
using namespace std;

int main() {
	Graph<char, unsigned> graph(6);

	GNode<char, unsigned> *n1 = graph.insNode('a');
	GNode<char, unsigned> *n2 = graph.insNode('b');
	GNode<char, unsigned> *n3 = graph.insNode('c');
	GNode<char, unsigned> *n4 = graph.insNode('d');
	GNode<char, unsigned> *n5 = graph.insNode('e');
	GNode<char, unsigned> *n6 = graph.insNode('f');

	GEdge<char, unsigned> *e1 = graph.insArco(n1, n2, 8);
	GEdge<char, unsigned> *e2 = graph.insArco(n1, n3, 2);
	GEdge<char, unsigned> *e3 = graph.insArco(n1, n4, 3);
	GEdge<char, unsigned> *e4 = graph.insArco(n2, n4, 4);
	GEdge<char, unsigned> *e5 = graph.insArco(n3, n2, 5);
	GEdge<char, unsigned> *e6 = graph.insArco(n3, n5, 9);
	GEdge<char, unsigned> *e7 = graph.insArco(n4, n3, 1);
	GEdge<char, unsigned> *e8 = graph.insArco(n4, n6, 1);

	cout << "---------------- BFS ----------------------------------" << endl;
	graph.BFS(n3);
	cout << "---------------- DFS ----------------------------------" << endl;
	graph.DFS(n3);
	cout << "---------------- DFS iterative ------------------------" << endl;
	graph.DFS_iterative(n3);

	cout << "---------------- Dijkstra Lower cost ------------------" << endl;


	HashTable<GNode<char, unsigned> *, unsigned> dist = Dijkstra(graph, n1);

	List<GNode<char, unsigned> *> keys_ = dist.keys();
	LNode<GNode<char, unsigned> *> *tmp = keys_.begin();


	while(!keys_.endList(tmp))
	{
		GNode<char, unsigned> *k = keys_.read(tmp);

		std::cout << graph.getValue(k) << " - " << dist.recupera(k) << std::endl;

		tmp = keys_.succList(tmp);
	}
	cout << "---------------- Iterative Deepining -------------------" << endl;

	char target = 'd';
	List<GNode<char, unsigned> *> res = graph.IDDFS(n1, n6, 0);
	LNode<GNode<char, unsigned> *> *t = res.begin();
	while(!res.endList(t))
	{
		GNode<char, unsigned> *iter = res.read(t);
		cout << "Goal: " << graph.getValue(iter) << endl;
		t = res.succList(t);
	}

	cout << "----------------- A* alghoritm / Dijkstra --------------------------"<< endl;
	List<GNode<char, unsigned> *> path = A_Star(graph, n1, n6);
	tmp = path.begin();

	while(!path.endList(tmp))
	{
		cout << graph.getValue(path.read(tmp)) << " ";

		tmp = path.succList(tmp);
	}




	return 0;
}
