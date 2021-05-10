#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 10

int *makeRandomArray(int size);
void freeArr(int *arr);
void printArr(int arr[], int size);
void swap(int *x, int *y);
void quickSort(int arr[], int, int);
int partition(int list[], int left, int right);

int main(){
#if 1
	int *randomArr;
    srand(time(0));
    randomArr = makeRandomArray(ARR_SIZE);
#endif
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
        *(arr+i) = rand() % 100;
    return arr;
}
void freeArr(int *arr){
    free(arr);
}
void printArr(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%-5d", arr[i]);
    printf("\n");
}
void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void quickSort(int arr[], int left, int right){
	if(left >= right)
		return;
	int low = left, high = right-1;
	int pivot = arr[right];

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
