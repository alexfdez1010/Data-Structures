//============================================================================
// Name        : FenwickTreeTest.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Test to check if the Fenwick tree works properly
//============================================================================

#include "FenwickTree.h"
#include <assert.h>
#include <iostream>

using namespace std;

int main(){


	int *array,*accu,sum,res,n,mult,i;

	n = 7;

	array = new int[n];
	accu = new int[n];

	array[0] = 3;
	array[1] = 7;
	array[2] = 8;
	array[3] = -3;
	array[4] = 2;
	array[5] = 5;
	array[6] = 7;

	accu[0] = array[0];
	for(i = 1;i < n;i++){
		accu[i] = accu[i-1] + array[i];
	}

	FenwickTree ft(n,array);

	for(i = 0;i < n;i++){
		assert(ft.query(i) == accu[i]);
		if(i > 0){
			assert(ft.query(i-1,i) == array[i]);
		}
	}

	array[3] = -2;
	ft.update(3, -2);

	sum = 0;
	for(i = 0;i < n;i++){
		sum += array[i];
		assert(ft.query(i) == sum);
		if(i > 0){
			assert(ft.query(i-1,i) == array[i]);
		}
	}

	FenwickTree ftMult(n,array,'*');

	mult = 1;
	for(i = 0;i < n;i++){
		mult *= array[i];
		assert(ftMult.query(i) == mult);
		if(i > 0){
			assert(ftMult.query(i-1,i) == array[i]);
		}
	}

	array[2] = -8;
	ftMult.update(2, -8);

	mult = 1;

	for(i = 0;i < n;i++){
		mult *= array[i];
		assert(ftMult.query(i) == mult);
		if(i > 0){
			assert(ftMult.query(i-1,i) == array[i]);
		}

	}

	array[0] = 0;
	array[1] = 1;
	array[2] = 0;
	array[3] = 1;
	array[4] = 1;
	array[5] = 1;
	array[6] = 0;

	FenwickTree ftXOR(n,array,'^');

	res = 0;
	for(i = 0;i < n;i++){
		res ^= array[i];
		assert(ftXOR.query(i) == res);
		if(i > 0){
			assert(ftXOR.query(i-1,i) == array[i]);
		}
	}

	array[6] ^= 1;
	ftXOR.update(6,array[3]);

	res = 0;
	for(i = 0;i < n;i++){
		res ^= array[i];
		assert(ftXOR.query(i) == res);
		if(i > 0){
			assert(ftXOR.query(i-1,i) == array[i]);
		}
	}

	delete array;
	delete accu;


}

