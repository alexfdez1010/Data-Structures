//============================================================================
// Name        : Graph.h
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Interface for a graph with the methods associated with it
//============================================================================

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef vector<pair<int,double> > vp;
typedef vector<vp> vvp;

template <class TYPE>
class Graph {

private:

	vvp adjList;

	vector<TYPE> intToType;

	unordered_map<TYPE,int> typeToInt;

	bool directed;

public:

	Graph(bool directed = true);
	~Graph();

	bool isEmpty() const;
	void addVertex(const TYPE &vertex);
	void addEdge(const TYPE &src, const TYPE &dst, double value = 1);
	set<TYPE> adjacent(const TYPE &vertex) const;
	set<TYPE> vertices() const;
	void deleteVertex(const TYPE &vertex);
	void deleteEdge(const TYPE &src, const TYPE &dst);

};



#endif /* GRAPH_H_ */
