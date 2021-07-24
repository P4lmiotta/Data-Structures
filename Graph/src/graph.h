/*
 * graph.h
 *
 *  Created on: 17 apr 2020
 *      Author: Alessandro Palmiotta
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include "List\src\linked_list.h"
#include "Stack\src\stack.h"
#include "Queue\src\queue.h"
#include "SBTree_Graph\src\sbtree.h"
#include "HashTable\src\hash.h"
#include "PriorityCode\src\prioritycode.h"

using namespace std;

template<typename T, typename W>
class GEdge;

template<typename T, typename W>
class Graph;

template<typename T, typename W>
class GNode{
	friend class Graph<T, W>;
private:
	int id;
	bool valid = false;
	bool visited = false; //for DFS_iterative
	GEdge<T, W> *edges;
public:
	//List<GNode<T, W> *> adiacents;
	T value;
	unsigned h; //for A* alghoritm
};

template<class T, class W>
class Hash<GNode<T, W> *>
{
public:
	size_t operator()(GNode<T, W> *n) const
	{
		return (size_t)n >> 4;
	}
};

template<typename T, typename W>
class GEdge{
	friend class Graph<T, W>;
private:
	GNode<T, W> *first;
	GNode<T, W> *second;
	W weight;
	bool valid = false;
};

template<typename T>
class DGNode{
public:
	DGNode()
	{ }

	DGNode(GNode<T, unsigned> *n, unsigned d = 0) :
		node(n), dist(d)
	{ }

	~DGNode()
	{ }

	GNode<T, unsigned> *node;
	unsigned dist;
};

template<typename T>
bool operator==(const DGNode<T> &a, const DGNode<T> &b)
{
	return a.node == b.node;
}

template<typename T>
bool operator<(const DGNode<T> &a, const DGNode<T> &b)
{
	return a.dist < b.dist;
}

template<typename T, typename W>
class Graph{
private:
	size_t m_size;

	size_t m_edges;
	GNode<T, W> *m_matrix;

public:
	List<GNode<T, W> *> nodes_;
	size_t m_nodes;

	Graph(size_t s);
	GNode<T, W>* insNode(T);
	GNode<T, W> * esisteNode(GNode<T, W>*);
	GEdge<T, W>* esisteArco(GNode<T, W>*, GNode<T, W>*) const;
	void writeNode(GNode<T, W>*, T value);
	W getWeight(GEdge<T, W>*) const;
	T getValue(GNode<T, W>*) const;
	GEdge<T, W>* insArco(GNode<T, W>*, GNode<T, W>*, W);
	List<GNode<T, W> *> adiacenti(GNode<T, W>*) const;
	bool hasAdiacents(GNode<T, W>*);
	List<GNode<T, W> *> getNodes() const;
	void DFS(GNode<T, W>*);
	void DFS_iterative(GNode<T, W>*);
	void BFS(GNode<T, W>*);
	void BFS_(GNode<T, W>*);
	List<GNode<T, W> *> DLS(GNode<T, W>*, GNode<T, W> *, size_t, bool);
	List<GNode<T, W> *> IDDFS(GNode<T, W>*, GNode<T, W> *, size_t);
};

template<typename T, typename W>
Graph<T, W>::Graph(size_t s){
	m_size = s;
	m_nodes = 0;
	m_edges = 0;
	m_matrix = new GNode<T, W>[m_size];

	for(size_t i = 0; i < m_size; i++)
		m_matrix[i].edges = new GEdge<T, W>[m_size];
}

template<typename T, typename W>
GNode<T, W>* Graph<T, W>::insNode(T v){
	if(m_nodes == m_size)
		throw "graph is full";

	size_t i = 0;
	while(m_matrix[i].valid)
		i++;

	m_matrix[i].valid = true;
	m_matrix[i].value = v;
	m_matrix[i].id = i;

	for(size_t j = 0; j < m_size; j++)
		m_matrix[i].edges[j].valid = false;

	m_nodes++;

	return &m_matrix[i];
}

template<typename T, typename W>
GEdge<T, W>* Graph<T, W>::insArco(GNode<T, W> *first, GNode<T, W> *second, W weight){
	if(esisteArco(first, second) != nullptr)
		throw "the edge already exists";

	first->edges[second->id].valid = true;
	first->edges[second->id].first = first;
	first->edges[second->id].second = second;
	first->edges[second->id].weight = weight;

	m_edges++;

	return &first->edges[second->id];
}

template<typename T, typename W>
W Graph<T, W>::getWeight(GEdge<T, W> *edge) const{
	return edge->weight;
}

template<typename T, typename W>
T Graph<T, W>::getValue(GNode<T, W> *node) const{
	return node->value;
}

template<typename T, typename W>
List<GNode<T, W> *> Graph<T, W>::adiacenti(GNode<T, W> *node) const{
	List<GNode<T, W> *> adj;

	for(size_t i = 0; i < m_size; i++)
		if(node->edges[i].valid)
			adj.pushBack(&m_matrix[i]);

	return adj;
}

template<typename T, typename W>
bool Graph<T, W>::hasAdiacents(GNode<T, W> *node){
	List<GNode<T, W> *> adj = adiacenti(node);
	if(!adj.empty()){
		return true;
	} else {
		return false;
	}
}

template<typename T, typename W>
void Graph<T, W>::writeNode(GNode<T, W> *node, T value){
	node->value = value;
}

template<typename T, typename W>
GNode<T, W> * Graph<T, W>::esisteNode(GNode<T, W> *node){
	List<GNode<T, W>*> n = nodes_;
	LNode<GNode<T, W> *> *temp = new LNode<GNode<T, W> *>;
	temp = n.begin();
	while(!n.endList(temp))
	{
		GNode<T, W>* p = n.read(temp);
		if(p == node){
			return p;
		}
		temp = n.succList(temp);
	}
	return nullptr;
}

template<typename T, typename W>
GEdge<T, W>* Graph<T, W>::esisteArco(GNode<T, W> *first, GNode<T, W> *second) const{
	if(first->edges[second->id].valid)
		return &first->edges[second->id];

	return nullptr;
}

template<typename T, typename W>
void Graph<T, W>::DFS(GNode<T, W> *node){
	Stack<GNode<T, W> *> stack;
	SearchTree<GNode<T, W> *> v;

	stack.push(node);
	v.insert(node);
	while(!stack.empty())
	{
		GNode<T, W> *temp = stack.top();
		stack.pop();
		std::cout << temp->value << std::endl;
		List<GNode<T, W> *> a = adiacenti(temp);
		LNode<GNode<T, W> *> *iter = new LNode<GNode<T, W> *>;
		iter = a.begin();
		while(!a.endList(iter))
		{
			GNode<T, W> *u = a.read(iter);
			if(!v.contains(u)){
				stack.push(u);
				v.insert(u);
			}
			iter = a.succList(iter);
		}
	}
}

template<typename T, typename W>
List<GNode<T, W> *> Graph<T, W>::getNodes() const
{
	List<GNode<T, W> *> l;

	for(size_t i = 0; i < m_size; i++)
		if(m_matrix[i].valid)
			l.pushBack(&m_matrix[i]);

	return l;
}

template<typename T, typename W>
void Graph<T, W>::DFS_iterative(GNode<T, W> *node){
	std::cout << node->value << std::endl;
	node->visited = true;
	List<GNode<T, W> *> adj = adiacenti(node);
	LNode<GNode<T, W> *> *iter = adj.begin();
	while(!adj.endList(iter))
	{
		GNode<T, W> *temp = adj.read(iter);
		if(temp->visited == false){
			DFS_iterative(temp);
		}
		iter = adj.succList(iter);
	}
}

template<typename T, typename W>
void Graph<T, W>::BFS(GNode<T, W> *node){
	Queue<GNode<T, W> *> queue;
	//SearchTree<GNode<T, W> *> v;
	List<GNode<T, W>*> visited;
	visited.pushBack(node); //v.insert(node);
	queue.push(node);
	while(!queue.empty())
	{
		GNode<T, W> *temp = queue.top();
		queue.pop();
		std::cout << temp->value << std::endl;

		List<GNode<T, W> *> a = adiacenti(temp);
		LNode<GNode<T, W> *> *iter = new LNode<GNode<T, W> *>;
		iter = a.begin();
		while(!a.endList(iter))
		{
			GNode<T, W> *u = a.read(iter);
			if(visited.find(u) == nullptr){
				queue.push(u);
				visited.pushBack(u); //v.insert(node);
			}
			iter = a.succList(iter);
		}
	}
}

template<class T, class W>
List<GNode<T, W> *> Graph<T, W>::DLS(GNode<T, W> *node, GNode<T, W> * goal, size_t b, bool hit_depth_bound){
	List<GNode<T, W> *> percorso;
	percorso.pushBack(node);
	if(b > 0){
		List<GNode<T, W> *> adj = adiacenti(node);
		LNode<GNode<T, W> *> *iter = adj.begin();
		while(!adj.endList(iter))
		{
			GNode<T, W> * temp = adj.read(iter);
			percorso = DLS(temp, goal, b - 1, hit_depth_bound);
			iter = adj.succList(iter);
		}
	} else if(node->value == goal->value){
		return percorso;
	} else if(hasAdiacents(node)){
		hit_depth_bound = true;
	}

}


template<class T, class W>
List<GNode<T, W> *> Graph<T, W>::IDDFS(GNode<T, W> *start, GNode<T, W> * goal, size_t bound){
	bool hit_depth_bound = false;
	List<GNode<T, W> *> result;
	do{
		result = DLS(start, goal, bound, hit_depth_bound);
		if(result.find(goal)){
			return result;
		}
		bound++;
	}while(hit_depth_bound == false);
}

template<typename T>
HashTable<GNode<T, unsigned> *, unsigned> Dijkstra(const Graph<T, unsigned> &graph, GNode<T, unsigned> *source);

//se h coincide con i costi dei vari archi, allora A* coincide con Dijkstra
template<typename T>
List<GNode<T, unsigned> *> A_Star(const Graph<T, unsigned> &graph, GNode<T, unsigned> *source, GNode<T, unsigned> *goal);

template<typename T>
HashTable<GNode<T, unsigned> *, unsigned> Dijkstra(const Graph<T, unsigned> &graph, GNode<T, unsigned> *source){
	PriorityCode<DGNode<T>> pqueue;
	HashTable<GNode<T, unsigned> *, unsigned> dist(graph.m_nodes);
	dist.inserisci(source, 0);
	pqueue.inserisci(DGNode<T>(source, 0));
	List<GNode<T, unsigned> *> nodes = graph.getNodes();
	LNode<GNode<T, unsigned> *> *temp = nodes.begin();
	while(!nodes.endList(temp))
	{
		GNode<T, unsigned> *vertex = nodes.read(temp);
		if(vertex != source)
			dist.inserisci(vertex, UINT_MAX);
		temp = nodes.succList(temp);
	}
	while(!pqueue.empty())
	{
		DGNode<T> u = pqueue.min();
		pqueue.cancellaMin();
		List<GNode<T, unsigned> *> adj = graph.adiacenti(u.node);
		temp = adj.begin();

		while(!adj.endList(temp))
		{
			GNode<T, unsigned> *vertex = adj.read(temp);
			GEdge<T, unsigned> *edge = graph.esisteArco(u.node, vertex);

			unsigned alt = dist.recupera(u.node) + graph.getWeight(edge);

			if(alt < dist.recupera(vertex))
			{
				dist.inserisci(vertex, alt);
				DGNode<T> d(vertex, alt);
				if(!pqueue.appartiene(d)){
					pqueue.inserisci(d);
				}
			}
			temp = adj.succList(temp);

		}
	}
	return dist;
}

template<typename T>
List<GNode<T, unsigned> *> A_Star(const Graph<T, unsigned> &graph, GNode<T, unsigned> *source, GNode<T, unsigned> *goal){
	//bool flag = false;
	PriorityCode<DGNode<T>> pqueue;
	HashTable<GNode<T, unsigned> *, unsigned> dist(graph.m_nodes);
	HashTable<GNode<T, unsigned> *, GNode<T, unsigned> *> parent(graph.m_nodes);

	dist.inserisci(source, 0);
	pqueue.inserisci(DGNode<T>(source, 0));

	List<GNode<T, unsigned> *> nodes = graph.getNodes();
	LNode<GNode<T, unsigned> *> *temp = nodes.begin();
	while(!nodes.endList(temp))
	{
		GNode<T, unsigned> *n = nodes.read(temp);
		if(n != source){
			dist.inserisci(n, UINT_MAX);
		}
		parent.inserisci(n, nullptr);
		temp = nodes.succList(temp);
	}
	while(!pqueue.empty())
	{
		DGNode<T> u = pqueue.min();
		pqueue.cancellaMin();

		List<GNode<T, unsigned> *> adj = graph.adiacenti(u.node);
		LNode<GNode<T, unsigned> *> *iter = adj.begin();
		while(!adj.endList(iter))
		{
			GNode<T, unsigned> *vertex = adj.read(iter);
			GEdge<T, unsigned> *edge = graph.esisteArco(u.node, vertex);
			unsigned distanza = dist.recupera(u.node) + graph.getWeight(edge);

			if(distanza < dist.recupera(vertex)){

				dist.inserisci(vertex, distanza);
				parent.inserisci(vertex, u.node);

				DGNode<T> pnode(vertex, distanza);

				if(!pqueue.appartiene(pnode)){
					pqueue.inserisci(pnode);
				}
			}
			iter = adj.succList(iter);
		}
	}
	List<GNode<T, unsigned> *> path;
	GNode<T, unsigned> *u = goal;
	if(parent.appartiene(u) || u == source){
		while(u != nullptr)
		{
			path.pushFront(u);
			u = parent.recupera(u);
		}
	}
	return path;
}


#endif /* GRAPH_H_ */
