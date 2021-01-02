//============================================================================
// Name        : UFDS.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Implementation of a Union-Find Disjoint Sets
//============================================================================

#include "UFDS.h"

UFDS::UFDS(unsigned int _size) {

	this -> _size = _size;

	sets = new unsigned int[_size];
	sizes = new unsigned int[_size];

	int i;

	for(i = 0;i < _size;i++){
		sets[i] = i;
		sizes[i] = 1;
	}

}

UFDS::~UFDS() {
	delete sets;
	delete sizes;
}

unsigned int UFDS::size() const {
	return this -> _size;
}

unsigned int UFDS::size(unsigned int n) const {
	return sizes[find(n)];
}

unsigned int UFDS::find(unsigned int n) const {

	while(n != sets[n]){
		n = sets[n];
	}

	return n;
}

void UFDS::join(unsigned int a, unsigned int b){

	unsigned int setA,setB;

	setA = find(a);
	setB = find(b);

	if(setA != setB){

		if(sizes[setA] >= sizes[setB]){
			sets[setB] = setA;
			sizes[setA] += sizes[setB];
		}

		else{
			sets[setA] = setB;
			sizes[setB] += sizes[setA];
		}

	}

}

bool UFDS::sameSet(unsigned int a, unsigned int b) const {
	return find(a) == find(b);
}
