#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int key;
	char value;
}element;
void selectionSortAsc(element item[], int size);
void swapElement(element*, element*);
void printElementArr(element item[], int size);

int main(){
	element item[4];
	item[0].key = 2;
	item[0].value = 'a';
	item[1].key = 1;
	item[1].value = 'b';
	item[2].key = 2;
	item[2].value = 'c';
	item[3].key = 1;
	item[3].value = 'd';

	printf("before sort\n");
	printElementArr(item, 4);

	selectionSortAsc(item, 4);

	printf("after sort\n");
	printElementArr(item, 4);
	return 0;	
}

void selectionSortAsc(element item[], int size){
	int i, j, least;
	for(i=0; i<size-1; i++){
		least = i;
		for(j=i+1; j<size; j++)
			if(item[least].key > item[j].key)
				least = j;
		swapElement(&item[least], &item[i]);
	}
}
void swapElement(element *x, element *y){
	element tmp;

	tmp.key = x->key;
	tmp.value = x->value;
	x->key = y->key;
	x->value = y->value;
	y->key = tmp.key;
	y->value = tmp.value;
}	
void printElementArr(element item[], int size){
	for(int i=0; i<size; i++){
		printf("%d : ", item[i].key);
		printf("%c : ", item[i].value);
	}
	printf("\n");
}


