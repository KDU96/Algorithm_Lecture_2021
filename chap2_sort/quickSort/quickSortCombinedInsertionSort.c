#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 10000

int *makeRandomArray(int size);
void freeArr(int *arr);
void printArr(int arr[], int size);
void swap(int *x, int *y);
void quickSort(int arr[], int, int);
int partition(int list[], int left, int right);
void checkSorting(int *arr, int size);
void insertionSort(int*, int, int);

int main(){
#if 1
    int *randomArr;
    srand(time(0));
    randomArr = makeRandomArray(ARR_SIZE);
#endif
    quickSort(randomArr, 0, ARR_SIZE-1);

	checkSorting(randomArr, ARR_SIZE);

    freeArr(randomArr);

    return 0;

}
int *makeRandomArray(int size){
    int *arr = (int*)malloc(sizeof(int) * size);
    int i;
    for(i=0; i<size; i++)
        *(arr+i) = rand() % 100;
    return arr;
}
void freeArr(int *arr){
    free(arr);
}
void printArr(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%-7d", arr[i]);
    printf("\n");
}
void swap(int *x, int *y){
    int tmp = *x; 
    *x = *y; 
    *y = tmp;
}
void checkSorting(int *arr, int size){
    int i;
    for(i=0; i<size-1; i++)
        if(arr[i] > arr[i+1]){
            printf("Sorting is failed\n");
            return;
        }
    printf("Sorting is success\n");
}
void insertionSort(int *arr, int left, int right){
	int i, j, key;
	for(i=left+1; i<=right; i++){
		key = arr[i];
		for(j=i-1; j>=left && key < arr[j]; j--)
			arr[j+1] = arr[j];
		arr[j+1] = key;
	}
}
void quickSort(int arr[], int left, int right){
    int low = left, high = right-1;
    int pivot = arr[right];

	if(right-left <= 20){
		insertionSort(arr, left, right);
		return;
	}
    while(low <= high){
        while(low <= high && arr[low] <= pivot)
            low++;
        while(low <= high && arr[high] >= pivot)
            high--;
        if(low < high)
            swap(&arr[low], &arr[high]);
    }   
    swap(&arr[low], &arr[right]);
    quickSort(arr, left, low-1);
    quickSort(arr, low+1, right);
}
