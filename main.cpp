//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include "util.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

	// variables for the parser...
	char c;
	int n, flag, value, index, dFlag, heapInValue;
	HEAP* heap;
	heap = NULL;
	ElementT heapElement;
	FILE* ifile;
	//FILE* ofile;
	while (1) {
		c = nextCommand();
		switch (c) {
		case 's':
		case 'S':	
					exit(0);

		case 'c':
		case 'C':	scanf("%d", &n);
					
					heap = heapInit(n);
					break;

		case 'r':
		case 'R':	scanf("%d", &flag);
					
					ifile = fopen("HEAPinput.txt", "r");
					if (!ifile) {
						cout << "Error: cannot open file for reading" << "\n";
						break;
					}
					fscanf(ifile, "%d", &n);
					if(heap == NULL || heap->capacity < n){
						cout << "Error: heap overflow" << "\n";
						break;
					}
				

					for (int i = 1; i <= n; i++) {
						fscanf(ifile, "%d", &heapInValue);
						heapElement = new ELEMENT;
						heapElement->key = heapInValue;
						heap->H[i] = heapElement;
						heap->size++;
					}
					
					buildHeap(heap);
					if (flag == 1) {
						printf("Number of Heapify calls: %d\n", getCount());
					}
					break;




		case 'p':
		case 'P':	
					if(heap == NULL){
						cout << "Error: cannot print" << "\n";
						break;
					}
					else {
						printHeap(heap);
						break;
					}
					




		case 'w':
		case 'W':	writeHeap(heap);
					break;

		case 'd':
		case 'D':	scanf("%d", &dFlag);

					if (heap == NULL || heap->size == 0) {
						cout << "Error: heap is NULL or empty" << "\n";
						break;
					}
					printf("Deleted key: %d\n", heapMin(heap));
					extractMin(heap);
					if (dFlag == 1) {
						printf("Number of Heapify calls: %d\n", getCount()); //NOT SURE IF THIS IS RIGHT!!!!!!!!
					}
						
					break;
					
		case 'i':
		case 'I':	scanf("%d", &value);
					if (heap == NULL || heap->size == heap->capacity) {
						cout << "Error: heap is NULL or full" << "\n";
						break;
					}
					heapElement = new ELEMENT;
					heapElement->key = value;
					insert(heap, heapElement);
					break;

		case 'k':
		case 'K':	scanf("%d", &index);
					scanf("%d", &value);
					if (heap == NULL || (index < 1 || index > heap->size) || value >= heap->H[index]->key) {
						cout << "Error: invalid call to DecreaseKey" << "\n";
						break;
					}
					decreaseKey(heap, index, value);
					buildHeap(heap);
					break;


		default: break;
		}
	}
		exit(0);
}

//=========================================================================================================			
