//heapify and heap sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 1000
using namespace std;

class MaxHeap{
    private :
        int heap_length;
        int heap[1000];
    public :
        MaxHeap();
        ~MaxHeap();
        void print_element() const;
        void insert_heap(int item);
        int delete_heap();
};
MaxHeap::MaxHeap(){
    heap_length = 0; 
}
MaxHeap::~MaxHeap(){
}

void MaxHeap::print_element() const{
    for(int i=1; i<=heap_length; i++)
        cout << heap[i] << ' ';
    cout << endl;
}
void MaxHeap::insert_heap(int item){
    int i = ++heap_length;
    while(i != 1){
        if(item <= heap[i/2])   break;
        else{
            heap[i] = heap[i/2];
            i /= 2;
        }
    }
    heap[i] = item;
}
int MaxHeap::delete_heap(){
    int deleted_item = heap[1];
    int temp = heap[heap_length];
    heap_length--;
    int i = 1, j = 2;
    while(j <= heap_length){
        if(heap[j] < heap[j+1]) j++;
        if(heap[j] < temp)   break;
        else{
            heap[i] = heap[j];
            i = j;  j *= 2;
        }
    }
    heap[i] = temp;
    return deleted_item;
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

int main(){
    int result[SIZE];
    srand(time(0));
    MaxHeap max_heap;
    for(int i=0; i <SIZE; i++)
        max_heap.insert_heap(rand() % SIZE);

    max_heap.print_element();
    cout << "After" << endl;
#if 1
    for(int i=0; i<SIZE; i++)
        cout << max_heap.delete_heap() << ' ';
#endif
    cout << endl;

}
    
