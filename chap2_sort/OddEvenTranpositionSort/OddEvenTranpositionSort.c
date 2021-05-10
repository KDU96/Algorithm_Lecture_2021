#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

int *makeRandomArray(int size);
void freeArr(int *arr);
void checkSorting(int *arr, int size);
void OddEvenTranspositionSort(int *arr, int size);
void *sortTwoData(void* arr);

int main(){
	int size;
	printf("Enter the Array size : ");
	scanf("%d", &size);
	int *arr = makeRandomArray(size);

	for(int i=0; i<size; i++)
		printf("%d  ", arr[i]);
	printf("\n\n");
//	int arr[size] = {2, 10, 5, 3, 7, 9, 4, 10, 8};
//
	OddEvenTranspositionSort(arr, size);
#if 1
	for(int i=0; i<size; i++)
		printf("%d  ", arr[i]);
	printf("\n");
#endif

	checkSorting(arr, size);

	freeArr(arr);
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
void checkSorting(int *arr, int size){
    int i;
    for(i=0; i<size-1; i++)
        if(arr[i] > arr[i+1]){
            printf("Sorting is failed\n");
            return;
        }
    printf("Sorting is success\n");
}
void *sortTwoData(void *arr){
	int *ptr = (int*)arr;
//	printf("%d\t%d\n", *ptr, *(ptr+1));
	if(*ptr > *(ptr+1)){
		int tmp = *ptr;
		*ptr = *(ptr+1);
		*(ptr+1) = tmp;
	}
}
void OddEvenTranspositionSort(int *arr, int size){
	int n = size / 2;
	int i, j, k;
	pthread_t sortingTread[n];
	
	for(i=0; i<size; i++){//odd sort
//		printf("odd sorting %d\n", i);
		for(j=0, k=0; j<size && k<n; j=j+2, k++){
			int thrID = pthread_create(&sortingTread[k], NULL, sortTwoData, (void*)(arr+j));
			if(thrID){
				fprintf(stderr, "thread error %d\n", k);
				exit(1);
			}
		}
		for(k=0; k<n; k++)
			pthread_join(sortingTread[k], NULL);

		int m = (size % 2 == 0) ? n-1 : n;

//		printf("even sorting %d\n", i);
		for(j=1, k=0; j<size && k<m; j=j+2, k++){
			int thrID = pthread_create(&sortingTread[k], NULL, sortTwoData, (void*)(arr+j));
			if(thrID){
				fprintf(stderr, "thread error %d\n", k);
				exit(1);
			}		
		}
		for(k=0; k<m; k++)
			pthread_join(sortingTread[k], NULL);
	}
}
