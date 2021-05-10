#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARR_SIZE 20

void insertionSort(int arr[], int size);
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

	insertionSort(randomArr, ARR_SIZE);

	printf("after sort\n");
    printArr(randomArr, ARR_SIZE);

    freeArr(randomArr);

	return 0;
}
void insertionSort(int arr[], int size){
	int i, j, key;
	for(i=1; i<size; i++){
		key = arr[i];	
		for(j=i-1; j>=0 && key < arr[j]; j--)
			arr[j+1] = arr[j];
		arr[j+1] = key;
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

