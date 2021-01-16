//============================================================================
// Name        : Graph.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Implementation of a graph with the methods associated with it
//============================================================================

#include "Graph.h"

template<class TYPE>
inline Graph<TYPE>::Graph(bool directed) {
	this -> directed = directed;
}

template<class TYPE>
inline Graph<TYPE>::~Graph() {

}

template<class TYPE>
inline void Graph<TYPE>::addVertex(const TYPE &vertex) {
	vp vec;
	intToType.push_back(vertex);
	typeToInt[vertex] =  intToType.size()-1;
	adjList.push_back(vec);
}

template<class TYPE>
inline void Graph<TYPE>::addEdge(const TYPE &src, const TYPE &dst,double value) {
	try{
		unsigned int s,d;
		s = typeToInt.at(src);
		d = typeToInt.at(dst);
		adjList[s].push_back(pair<int,double>(d,value));
		if(!directed)
			adjList[d].push_back(pair<int,double>(s,value));
	}
	catch(out_of_range &e){
		cerr << "The source or destiny doesn´t exists in the graph" << endl;
	}
}

template<class TYPE>
inline set<TYPE> Graph<TYPE>::adjacent(const TYPE &vertex) const {
	set<TYPE> s;
	unsigned int v,i;
	v = typeToInt.at(vertex);
	for(i = 0;i < adjList[v].size();i++){
		s.insert(intToType[adjList[v][i].first]);
	}
	return s;
}

template<class TYPE>
inline bool Graph<TYPE>::isEmpty() const {
	return adjList.size() == 0;
}

template<class TYPE>
inline set<TYPE> Graph<TYPE>::vertices() const {
	set<TYPE> s;
	TYPE ele;
	int i;
	for(i = 0;i < intToType.size();i++){
		ele = intToType[i];
		s.insert(ele);
	}
	return s;
}

template<class TYPE>
inline void Graph<TYPE>::deleteVertex(const TYPE &vertex) {
	unsigned int v,i,j;

	v = typeToInt.at(vertex);

	typeToInt.erase(vertex);

	for(i = 0;i < adjList.size();i++){
		for(j = 0;j < adjList[i].size();j++){
			if(adjList[i][j].first == v){
				adjList[i].erase(adjList[i].begin()+j);
			}
		}
	}

	adjList[v].clear();
	adjList.erase(adjList.begin()+v);

	intToType.erase(intToType.begin()+v);
}

template<class TYPE>
inline void Graph<TYPE>::deleteEdge(const TYPE &src, const TYPE &dst) {

	unsigned int i,s,d;

	s = typeToInt.at(src);
	d = typeToInt.at(dst);

	for(i = 0;i < adjList[s].size();i++){
		if(adjList[s][i].first == d){
			adjList[s].erase(adjList[s].begin()+i);
		}
	}

	if(!directed){
		for(i = 0;i < adjList[d].size();i++){
			if(adjList[d][i].first == s){
				adjList[d].erase(adjList[d].begin()+i);
			}
		}
	}

}
