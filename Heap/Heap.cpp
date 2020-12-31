//============================================================================
// Name        : Heap.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Simple implementation of a heap that can have different number of childs
//============================================================================

#include "Heap.h"

template<class TYPE>
inline Heap<TYPE>::Heap(bool _minHeap, unsigned int _childs) {
	minHeap = _minHeap;
	_size = 0;
	childs = _childs;
	vector = new TYPE[MAX];
}

template<class TYPE>
inline Heap<TYPE>::~Heap() {
	delete vector;
}

template<class TYPE>
inline bool Heap<TYPE>::empty() {
	return size() == 0;
}

template<class TYPE>
inline unsigned int Heap<TYPE>::size() {
	return _size;
}

template<class TYPE>
inline TYPE Heap<TYPE>::top() {
	return vector[0];
}

template<class TYPE>
inline void Heap<TYPE>::top(TYPE &ele) {
	ele = vector[0];
}

template<class TYPE>
inline void Heap<TYPE>::push(const TYPE &ele) {

	unsigned int n, pos;
	bool change;

	if(size()+1 != MAX){
		n = size();
		vector[n] = ele;
		_size++;

		if(n != 0){

			do{
				pos = (n-1)/childs;
				change = comp(vector[n],vector[pos]);
				if(change){
					swap(vector[n],vector[pos]);
				}
				n = pos;
			}
			while(n != 0 && change);
		}
	}

}

template<class TYPE>
inline TYPE Heap<TYPE>::pop() {
	TYPE ele = vector[0];
	sink();

}

template<class TYPE>
inline void Heap<TYPE>::pop(TYPE &ele) {
	if(!empty()){
		ele = vector[0];
		sink();
	}
}

template<class TYPE>
inline void Heap<TYPE>::sink() {
	unsigned int n,i,limit,select;

	n = 0;
	select = 1;

	while(size() > select){

		limit = childs*(n+1);

		for(i = select+1;i <= limit && i < size();i++){

			if(comp(vector[i],vector[select])){
				select = i;
			}
		}

		swap(vector[select],vector[n]);

		n = select;
		select = childs*n+1;
	}

	while(n < size()-1){
		vector[n] = vector[n+1];
		n++;
	}

	_size--;

}

template<class TYPE>
inline void Heap<TYPE>::swap(TYPE &a, TYPE &b) {
	TYPE c;

	c = a;
	a = b;
	b = c;
}

template<class TYPE>
inline bool Heap<TYPE>::comp(const TYPE &a, const TYPE &b) {
	return (a > b) ^ minHeap;
}
