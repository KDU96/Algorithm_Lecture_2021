#include <iostream>
using namespace std;

//max heap

void HeapSort(int a[]);
void heapfiy(int a[], int h, int m);

int main(){
}
void HeapSort(int a[]){
    
}

void heapfiy(int a[], int h, int m){//h:header, m:max index
    int v = a[h];
    for(int j = 2*h; j <= m; j *= 2){
        if(j < m && a[j] < a[j+1]) j++;
        if(v >= a[j]) return;
        else a[j/2] = a[j];
    }
    a[j/2] = v;
}
