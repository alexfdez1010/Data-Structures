//============================================================================
// Name        : UFDS.h
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Interface for the use of a Union-Find Disjoint Sets
//============================================================================

#ifndef UFDS_H_
#define UFDS_H_

class UFDS {

private:

	unsigned int *sets;

	unsigned int *sizes;

	unsigned int _size;

public:

	//PRE: {_size > 0}
	//DESC: Constructor an object of type Union-Find Disjoint Sets
	//PARAM: {_size number of elements}
	//COMPLEXITY: O(n) SoP: _size
	UFDS(unsigned int _size);

	//PRE: {}
	//DESC: Destructor an object of type Union-Find Disjoint Sets
	//PARAM: {}
	//COMPLEXITY: O(1)
	~UFDS();

	//PRE: {}
	//DESC: Returns the total size of the Union-Find Disjoint Sets
	//PARAM: {}
	//COMPLEXITY: O(1)
	unsigned int size() const;

	//PRE: {n < size()}
	//DESC: Returns the size of the set that belongs a
	//PARAM: {n element of the UFDS}
	//COMPLEXITY: O(1)
	unsigned int size(unsigned int n) const;

	//PRE: {n < size()}
	//DESC: Returns at what set belongs n
	//PARAM: {n element of the UFDS}
	//COMPLEXITY: O(1)
	unsigned int find(unsigned int n) const;

	//PRE: {a < size() && b < size()}
	//DESC: Union of the sets that belong a and b, in case that there are in the same set it will do nothing
	//PARAM: {a,b elements of the UFDS}
	//COMPLEXITY: O(1)
	void join(unsigned int a,unsigned int b);

	//PRE: {a < size() && b < size()}
	//DESC: Returns true if they are in the same set otherwise false
	//PARAM: {a,b elements of the UFDS}
	//COMPLEXITY: O(1)
	bool sameSet(unsigned int a,unsigned int b) const;

};

#endif /* UFDS_H_ */
