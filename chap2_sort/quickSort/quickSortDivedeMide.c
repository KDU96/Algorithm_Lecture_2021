#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 100000

void printArr(int arr[], int size);
void swapArr(int*, int, int);
void quickSort(int arr[], int, int);
int *makeRandomArray(int size);
void freeArr(int *arr);

int main(){
    int *randomArr;
    srand(time(0));
    randomArr = makeRandomArray(ARR_SIZE);

    printf("before sort\n");
    printArr(randomArr, ARR_SIZE);

    quickSort(randomArr, 0, ARR_SIZE-1);

    printf("after sort\n");
    printArr(randomArr, ARR_SIZE);

    freeArr(randomArr);

    return 0;

}
int *makeRandomArray(int size){
    int *arr = (int*)malloc(sizeof(int) * size);
    int i;
    for(i=0; i<size; i++)
        *(arr+i) = rand() % 1000000;
    return arr;
}
void freeArr(int *arr){
    free(arr);
}
void printArr(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%-6d", arr[i]);
    printf("\n");
}
void swapArr(int *arr, int left, int right){
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
void quickSort(int arr[], int left, int right){
	int low, high, mid, pivot;
	if(right - left > 1){
		mid = (left + right) / 2;
		if(arr[left] > arr[mid])
			swapArr(arr, left, mid);
		if(arr[left] > arr[right])
			swapArr(arr, left, right);
		if(arr[mid] > arr[right])
			swapArr(arr, mid, right);
		swapArr(arr, mid, right-1);

		low = left;	high = right - 1;	pivot = arr[right-1];

		while(1){
			while(arr[++low] < pivot);
			while(arr[--high] > pivot);
			if(low >= high)
				break;
			swapArr(arr, low, high);
		}
		swapArr(arr, low, right-1);
		quickSort(arr, left, low-1);
		quickSort(arr, low+1, right);
	}
	else if(arr[left] > arr[right])
		swapArr(arr, left, right);
}
