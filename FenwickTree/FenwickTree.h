//============================================================================
// Name        : FenwickTree.h
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Interface for a Fenwick tree that allow implementation with addition,
//               multiplication and logic gate XOR
//============================================================================

#ifndef FENWICKTREE_H_
#define FENWICKTREE_H_

class FenwickTree {
private:

	int * array;

	unsigned int n;

	char oper;

public:

	//PRE: {_size > 0 && sizeof(array)/sizeof(int) == _size && (oper == '+' || oper == '*' || oper == '^')}
	//DESC: Constructor of a Fenwick Tree
	//PARAM: {_size number of elements, _array with the numbers to use in the tree, _oper operation of the tree}
	//COMPLEXITY: O(n) SoP: _size
	FenwickTree(unsigned int _size,int * _array, char _oper = '+');

	//PRE: {}
	//DESC: Destructor of a Fenwick Tree
	//PARAM: {}
	//COMPLEXITY: O(1)
	~FenwickTree();

	//PRE: {}
	//DESC: Returns the size of the Fenwick Tree
	//PARAM: {}
	//COMPLEXITY: O(1)
	unsigned int size() const;

	//PRE: {}
	//DESC: Update the position pos with the value newValue
	//PARAM: {pos position to change,newValue the new value for the position}
	//COMPLEXITY: O(log(n))
	void update(unsigned int pos,int newValue);

	//PRE: {pos >= 0}
	//DESC: Returns the accumulate between 0 and pos both include
	//PARAM: {pos position to get the accumulate between 0 and this position}
	//COMPLEXITY: O(log(n))
	int query(unsigned int pos) const;

	//PRE: {start >= 0 && end > start}
	//DESC: Returns the accumulate between start and end both include
	//PARAM: {start,end positions to get the accumulate between them}
	//COMPLEXITY: O(log(n))
	int query(unsigned int start,unsigned int end) const;

	//PRE: {pos >= 0}
	//DESC: Returns the value of the position pos
	//PARAM: {pos position to get the value}
	//COMPLEXITY: O(log(n))
	int getPos(unsigned int pos) const;

};

#endif /* FENWICKTREE_H_ */
