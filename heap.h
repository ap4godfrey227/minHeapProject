#ifndef _HEAP_H
#define _HEAP_H



typedef struct TAG_ELEMENT{
	int key;
}ELEMENT;

typedef ELEMENT *ElementT;

typedef struct TAG_HEAP{
	int capacity;
	int size;
	ElementT *H;
}HEAP;

HEAP* heapInit(int n);

void printHeap(HEAP* heap);

void writeHeap(HEAP* heap);

void insert(HEAP* heap, ElementT element);

int heapMin(HEAP* heap);

int findParent(HEAP* heap, int index);

void extractMin(HEAP* heap);

void decreaseKey(HEAP* heap, int index, int value);

void buildHeap(HEAP* heap);

void minHeapify(HEAP * heap, int index);

int getCount();

void setCount(int value);

void count();
#endif
