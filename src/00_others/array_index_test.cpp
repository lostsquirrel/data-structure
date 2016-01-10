/*
 * array_index_test.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: lisong
 */

#include <iostream>
using namespace std;

int main(void) {

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	cout<<a[3]<<endl;
	// 3-7
	int *b = a + 3;
	cout<<b[0]<<endl<<b[4]<<endl;
	return 0;
}
