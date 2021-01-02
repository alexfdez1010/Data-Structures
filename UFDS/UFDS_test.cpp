//============================================================================
// Name        : UFDS_test.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Tests to check if the Union-Find Disjoint Sets works properly
//============================================================================

#include "UFDS.h"
#include <assert.h>

int main(){
	UFDS u(10);

	assert(!u.sameSet(0,1));
	u.join(0,1);
	assert(u.sameSet(0,1));

	u.join(1,2);
	u.join(8,9);
	u.join(9,2);

	assert(u.sameSet(1,9));
	assert(u.sameSet(0,8));
	assert(u.sameSet(2,0));
	assert(!u.sameSet(5,9));

	u.join(3,4);
	u.join(4,5);
	u.join(5,6);

	assert(!u.sameSet(6,9));
	assert(u.sameSet(6,3));
	assert(!u.sameSet(3,2));

	u.join(2,6);
	u.join(7,2);

	int i,j;

	for(i = 0;i < u.size();i++){
		for(j = i+1;j < u.size();j++){
			assert(u.sameSet(i,j));
		}
	}

}

