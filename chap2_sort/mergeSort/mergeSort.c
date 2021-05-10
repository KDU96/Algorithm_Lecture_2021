#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARR_SIZE 100

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int right, int mid);
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
    mergeSort(randomArr, 0, ARR_SIZE-1);
    printf("after sort\n");
    printArr(randomArr, ARR_SIZE);
    freeArr(randomArr);
    return 0;
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
void merge(int arr[], int left, int right, int mid){
	int i=left, j=mid+1, k=0, m=0;
	int *temp = (int*)malloc(sizeof(int) * (right-left + 1));
	while(i<=mid && j<=right){
		if(arr[i] < arr[j]){
			temp[k] = arr[i];
			i++;	k++;
		}
		else{
			temp[k] = arr[j];
			j++;	k++;
		}
	}
	if(i>mid){
		for(int l=j; l<=right; l++, k++){
			temp[k] = arr[l];
		}
	}
	else{
		for(int l=i; l<=mid; l++, k++){
			temp[k] = arr[l];
		}
	}
	for(int l=left; l<=right; l++, m++){
		arr[l] = temp[m];
	}
	free(temp);
}
void mergeSort(int arr[], int left, int right){
	int mid = (left + right) / 2;
	if(left < right){
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, right, mid);
	}
}
