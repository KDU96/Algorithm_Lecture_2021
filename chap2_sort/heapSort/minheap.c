#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_HEAP_SIZE 10000

typedef struct element{
	int key;
}element;
typedef struct HeapType{
	int heapSize;
	element heap[MAX_HEAP_SIZE];
}HeapType;

void initMinHeap(HeapType *h);
void insertMinHeap(HeapType *h, element item);
element deleteMinHeap(HeapType *h);
element* randomElementGenerator(int size);
void freeElement(element*);
void checkSort(int *arr, int);

int main(){
	element *rndElement;
	int arr[MAX_HEAP_SIZE-1];
	HeapType h;
	initMinHeap(&h);

	srand(time(0));

	rndElement = randomElementGenerator(MAX_HEAP_SIZE-1);

	for(int i=0; i<MAX_HEAP_SIZE-1; i++)
		insertMinHeap(&h, rndElement[i]);
	for(int i=0; i<MAX_HEAP_SIZE-1; i++)
		arr[i] = deleteMinHeap(&h).key;

	checkSort(arr, MAX_HEAP_SIZE-1);

	return 0;
}
element* randomElementGenerator(int size){
	element *ptr = (element*)malloc(sizeof(element) * size);
	for(int i=0; i<size; i++)
		ptr[i].key = rand() % size;
	return ptr;
}
void freeElement(element* ptr){
	free(ptr);
}
void initMinHeap(HeapType *h){
	h->heapSize = 0;
}
void insertMinHeap(HeapType *h, element item){
	int i = ++(h->heapSize);
	while((i != 1) && h->heap[i/2].key > item.key){
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}
void checkSort(int *arr, int size){
	for(int i=0; i<size-1; i++){
		if(arr[i] > arr[i+1]){
			printf("Sort is failed\n");
			return;
		}
	}
	printf("Sort is successful\n");
}
element deleteMinHeap(HeapType *h){
	int parent = 1, child = 2;
	element tmp = h->heap[1];
	element item = h->heap[(h->heapSize)--];

	while(child <= h->heapSize){
		if(h->heap[child].key > h->heap[child+1].key)
			child++;
		if(h->heap[child].key > item.key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = item;
	return tmp;
}
