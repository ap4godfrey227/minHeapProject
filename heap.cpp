#include "heap.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int heapifyCount = 0;
FILE* ofile;

HEAP* heapInit(int n){
	HEAP* heap = new HEAP();
	heap->capacity = n;
	heap->size = 0;
	heap->H = new ElementT[n+1];
	return heap;
}

void printHeap(HEAP* heap){
	printf("capacity=%d, size=%d\n", heap->capacity, heap->size);
	if (heap->size == 0) {
		return;
	}
	for (int i = 1; i <= heap->size; i++) {
		if(i == heap->size){
			printf("%d", heap->H[i]->key);
		}
		else{
			printf("%d, ", heap->H[i]->key);
		}
	}
	printf("\n");
}

void writeHeap(HEAP* heap) {
	ofile = fopen("HEAPoutput.txt", "w");
	if (!ofile) {
		cout << "Error: cannot write" << "\n";
		return;
	}
	if (heap == NULL) {
		cout << "Error: cannot write" << "\n";
		return;
	}
	fprintf(ofile, "%d\n", heap->size);
	for (int i = 1; i <= heap->size; i++) {
		fprintf(ofile, "%d\n", heap->H[i]->key);
	}
	fclose(ofile);

}

void insert(HEAP* heap, ElementT element) {
	int i;
	heap->size++;
	i = heap->size;
	while (i > 1 && heap->H[findParent(heap, i)]->key < element->key) {
		heap->H[i] = heap->H[findParent(heap, i)];
		i = findParent(heap, i);
	}
	heap->H[i] = element;
	buildHeap(heap);
	/*heap->H[i]->key = 1000000000;
	decreaseKey(heap, i, element->key);*/
}

int heapMin(HEAP* heap) {
	return heap->H[1]->key;
}

void extractMin(HEAP* heap) {
		setCount(0);
		heap->H[1]->key = heap->H[heap->size]->key;
		heap->size--;
		minHeapify(heap, 1);
}

void decreaseKey(HEAP* heap, int index, int value) {
	ElementT temp;
	heap->H[index]->key = value;
	while (index > 1 && heap->H[findParent(heap, index)]->key < heap->H[index]->key) {
		temp = heap->H[findParent(heap, index)];
		heap->H[findParent(heap, index)] = heap->H[index];
		heap->H[index] = temp;
		index = findParent(heap, index);
	}
}

int findParent(HEAP* heap, int index) {
	if (index == 1) {
		return 1;
	}
	else {
		if (index % 2 == 0) {
			return index / 2;
		}
		else {
			return (index-1) / 2;
		}
	}
}


void buildHeap(HEAP* heap) {
	for (int i = floor (heap->size / 2.0); i >= 1; i--) {
		
		minHeapify(heap, i);
		
	}
}
void minHeapify(HEAP* heap, int index) {
	
	int smallest;
	ElementT temp;
	

	int left = 2*index;
	int right = 2*index + 1;

	
	if (left <= heap->size && heap->H[left]->key < heap->H[index]->key) {
		smallest = left;
		
	}
	else {
		smallest = index;
		
	}
	if (right <= heap->size && heap->H[right]->key < heap->H[smallest]->key) {
		smallest = right;
		
	}
	count();
	if (smallest != index) {
		
		temp = heap->H[smallest];
		heap->H[smallest] = heap->H[index];
		heap->H[index] = temp;
		//heapifyCount--;
		minHeapify(heap, smallest);
	}

}

int getCount() {
	return heapifyCount;
}

void setCount(int value) {
	heapifyCount = value;
}

void count() {
	heapifyCount++;
}
