/*
 * 1_demo_1.c
 *
 *  Created on: Oct 24, 2015
 *      Author: lisong
 *      bubble sort
 *      do
 swapped = false
 for i = 1 to indexOfLastUnsortedElement
 if leftElement > rightElement
 swap(leftElement, rightElement)
 swapped = true
 while swapped
 */

#include <stdio.h>

void swap(int *left, int *right) {
	int temp = *left;
	*left = *right;
	*right = temp;
}

void bubbleSort1A(int a[], int n) {
	int i, swapped;
	do {
		swapped = 0;
		for (i = 1; i < n; i++) {
			if (a[i - 1] > a[i]) {
				swap(&a[i - 1], &a[i]);
				swapped = 1;
			}
		}
		n--;
	} while (swapped);
}
//repeat (numOfElements - 1) times
//  set the first unsorted element as the minimum
//  for each of the unsorted elements
//    if element < currentMinimum
//      set element as new minimum
//  swap minimum with first unsorted position
void selectSort(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int min = i - 1;
		for (j = i; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		swap(&a[i - 1], &a[min]);
	}
}
/*
 mark first element as sorted
 for each unsorted element
 'extract' the element
 for i = lastSortedIndex to 0
 if currentSortedElement > extractedElement
 move sorted element to the right by 1
 else: insert extracted element
 */
void insertSort(int a[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > temp) {
				a[j + 1] = a[j];
			} else {
				a[j + 1] = temp;
				break;
			}
//			printf("%d\n", a[j + 1]);
//			print(a, n);
		}
//		printf("%d\n", temp);
//		printf("---------------\n");
	}
}

void mergeSort(int a[], int n) {

}

void print(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

int main(void) {
	int a[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int n = 15;

	print(a, n);
//	bubbleSort1A(a,n);
//	selectSort(a, n);
	insertSort(a, n);
	print(a, n);
	while (1) {
		print(a, n);
	}
	return 0;
}
