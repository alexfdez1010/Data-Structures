//============================================================================
// Name        : FenwickTree.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Implementation of a Fenwick tree that allow implementation with addition,
//               multiplication and logic gate XOR
//============================================================================

#include "FenwickTree.h"

FenwickTree::FenwickTree(unsigned int _size, int *_array, char _oper) {

	n = _size;
	array = new int[_size+1];
	oper = _oper;

	int i,j;

	for(i = 1;i <= _size;i++){
		array[i] = _array[i-1];
	}

	for(i = 1;i <= _size;i++){

		j = i + (i & -i);

		if (j <= n){

			switch(_oper){

			case '+':
				array[j] += array[i];
				break;

			case '*':
				array[j] *= array[i];
				break;

			case '^':
				array[j] ^= array[i];
				break;

			}
		}
	}
}

FenwickTree::~FenwickTree() {
	delete array;
}

unsigned int FenwickTree::size() const{
	return n;
}

void FenwickTree::update(unsigned int pos, int newValue) {
	int lastValue;

	lastValue = getPos(pos);

	pos++;

	while(pos <= size()){

		switch(oper){

		case '+':
			array[pos] += newValue - lastValue;
			break;

		case '*':
			array[pos] /= lastValue;
			array[pos] *= newValue;
			break;

		case '^':
			array[pos] ^= newValue ^ lastValue;
			break;
		}

		pos += (pos & -pos);
	}

}

int FenwickTree::query(unsigned int pos) const {
	int res;

	if(oper == '*'){
		res = 1;
	}
	else{
		res = 0;
	}

	pos++;

	while(pos != 0){

		switch(oper){

		case '+':
			res += array[pos];
			break;

		case '*':
			res *= array[pos];
			break;

		case '^':
			res ^= array[pos];
			break;
		}
		pos -= (pos & -pos);

	}
	return res;
}

int FenwickTree::query(unsigned int start, unsigned int end) const {
	int query1,query2;

	query1 = query(start);
	query2 = query(end);

	switch(oper){
	case '+':
		return query2 - query1;
		break;

	case '*':
		return query2/query1;
		break;

	case '^':
		return query2^query1;
		break;
	}

	return 0;
}

int FenwickTree::getPos(unsigned int pos) const {
	int value;
	if(pos == 0){
		value = array[1];
	}

	else{

		switch(oper){

		case '+':
			value = query(pos) - query(pos-1);
			break;

		case '*':
			value = query(pos) / query(pos-1);
			break;

		case '^':
			value = query(pos) ^ query(pos-1);
			break;

		}

	}
	return value;
}
