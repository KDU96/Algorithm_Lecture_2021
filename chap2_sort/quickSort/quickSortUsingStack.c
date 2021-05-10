#ifndef STACK_C
#define STACK_C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10000
#define ARR_SIZE 1000
void printArr(int arr[], int size);
void swapArr(int*, int, int);
void quickSort(int arr[], int, int);
int *makeRandomArray(int size);
void freeArr(int *arr);
int partition(int* arr, int left, int right);
void checkSorting(int*, int);
typedef struct MyStack{
    int stack[MAX_STACK_SIZE];
    int top;
}MyStack;
void initMyStack(MyStack *s);
void push(MyStack* s, int element);
int pop(MyStack *s);


int main(){
    int *randomArr;
    srand(time(0));
    randomArr = makeRandomArray(ARR_SIZE);

//    printf("before sort\n");
//    printArr(randomArr, ARR_SIZE);

    quickSort(randomArr, 0, ARR_SIZE-1);

	checkSorting(randomArr, ARR_SIZE);
//    printf("after sort\n");
//    printArr(randomArr, ARR_SIZE);

    freeArr(randomArr);

    return 0;

}
void initMyStack(MyStack *s){
	s->top = -1;
}
void push(MyStack* s, int element){
    if(top < MAX_STACK_SIZE-1){
        fprintf(stderr, "stack is full\n");
        return;
    }   
    (s->top)++;
    s->stack[s->top] = element;
}
int pop(MyStack *s){
    if(top == -1){
        fprintf(stderr, "stack is empty\n");
        return -1; 
    }   
    return s->stack[s->top--];
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
void checkSorting(int *arr, int size){
	int i;
	for(i=0; i<size-1; i++)
		if(arr[i] > arr[i+1]){
			printf("Sorting is failed\n");
			return;
		}
	printf("Sorting is success\n");
}
int partition(int* arr, int left, int right){
	int i = left, j=right-1;
	int pivot = arr[right];

	while(left <= right){
		while(i<=j && arr[i] <= pivot)
			i++;
		while(i<=j && arr[j] >= pivot)
			j++;
		if(i < j)
			swapArr(arr, i, j);
	}
	swapArr(arr, i, right);
	return i;
}

void quickSort(int arr[], int l, int r){
	int i, j ,v;
	MyStack s;
	initMyStack(&s);

	while(1){
		while(r > l){
			i = partition(a, l ,r);
			if(i-l > r-i){
				push(&s, l);  push(&s, i-1);  l=i+1;
			}
			else{
				push(&s, i+1);  push(&s, r);  r= i-1;
			}
		}
		if(s->top <0)
			break;
		r = pop(&s);
		l = pop(&s);
	}
}

