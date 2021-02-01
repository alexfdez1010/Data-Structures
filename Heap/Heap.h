//============================================================================
// Name        : Heap.h
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Interface of a simple implementation of a heap that can have different number of childs
//============================================================================

#ifndef HEAP_H_
#define HEAP_H_

const unsigned int MAX = 10000;

template<class TYPE>
class Heap {

private:

	bool minHeap;

	unsigned int childs;

	unsigned int _size;

	TYPE *vector;

	void sink();

	void swap(TYPE &a, TYPE &b);

	bool comp(const TYPE &a,const TYPE &b);

public:

	//Constructor
	//_minHeap true if is minimum heap in case of being a maximum heap is false
	//_childs maximum number of childs that can have a node, recommended to be equal 3
	//PRE: {_childs >= 2}
	//RETURN:
	//COMPLEXITY: O(1)
	Heap(bool _minHeap = true, unsigned int _childs = 3);

	//Destructor
	//PRE:
	//RETURN:
	//COMPLEXITY: O(1)
	~Heap();

	//Check if the heap is empty
	//PRE: {}
	//RETURN: {Returns true if the heap is empty otherwise false}
	//COMPLEXITY: O(1)
	bool empty();

	//Get the size of the heap
	//PRE: {}
	//RETURN: {The number of elements of the heap}
	//COMPLEXITY: O(1)
	unsigned int size();

	//Get the top element of the heap
	//PRE: {!empty()}
	//RETURN: {Returns the top element of the heap}
	//COMPLEXITY: O(1) SoP : size()
	TYPE top();

	//Get the top element of the heap
	//PRE: {!empty()}
	//RETURN: {Returns the top element of the heap in ele}
	//COMPLEXITY: O(1) SoP : size()
	void top(TYPE &ele);

	//Push ele in the heap keeping the order
	//PRE: {size() < MAX}
	//RETURN: {}
	//COMPLEXITY: O(log n) SoP : size()
	void push(const TYPE &ele);

	//Pop the top element and also returns it keeping the order
	//PRE: {!empty()}
	//RETURN: {Returns the top element of the heap in ele}
	//COMPLEXITY: O(log n) SoP : size()
	TYPE pop();

	//Pop the top element and also returns it in ele keeping the order
	//PRE: {!empty()}
	//RETURN: {Returns the top element of the heap in ele}
	//COMPLEXITY: O(log n) SoP : size()
	void pop(TYPE &ele);

};

#endif /* HEAP_H_ */
