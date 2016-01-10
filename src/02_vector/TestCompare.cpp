/*
 * test_compare.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: lisong
 */
 typedef int Rank; //秩
#include <iostream>
#include "VectorUtils.h"
using namespace std;

int main(void) {

	Rank a = 3;
	Rank b = 5;
//	int *c = &a;
//	int *d = &b;
	cout<<lt(a, b)<<endl;
	cout<<eq(a, b)<<endl;
	cout<<lt(&a, &b)<<endl;
	cout<<eq(&a, &b)<<endl;
//	cout<<lt(c, d)<<endl;
//	cout<<eq(c, d)<<endl;
	return 0;
}
