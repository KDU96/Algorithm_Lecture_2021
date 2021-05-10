#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 30

void selectionSortDsc(int arr[], int size);
int *makeRandomArray(int size);
void freeArr(int *arr);
void printArr(int arr[], int size);
void swap(int *x, int *y);

int main(){
	int *randomArr;
	srand(time(0));
	randomArr = makeRandomArray(ARR_SIZE);
	printf("before sort\n");
	printArr(randomArr, ARR_SIZE);

	selectionSortDsc(randomArr, ARR_SIZE);
	printf("after sort\n");
	printArr(randomArr, ARR_SIZE);

	freeArr(randomArr);
	return 0;	
}

void selectionSortDsc(int arr[], int size){
	int i, j, largest;
	for(i=0; i<size-1; i++){
		largest = i;
		for(j=i+1; j<size; j++)
			if(arr[largest] < arr[j])
				largest = j;
		swap(&arr[i], &arr[largest]);
	}
}
int *makeRandomArray(int size){
	int *arr = (int*)malloc(sizeof(int) * size);
	int i;
	for(i=0; i<size; i++)
		*(arr+i) = rand() % ARR_SIZE;
	return arr;
}
void freeArr(int *arr){
	free(arr);
}
void printArr(int arr[], int size){
	for(int i=0; i<size; i++)
		printf("%-3d", arr[i]);
	printf("\n");
}
void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
	


