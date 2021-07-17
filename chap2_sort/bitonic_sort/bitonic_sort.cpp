#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sort_Element{
    public :
        static void asc_sort(int arr[], int x, int y);
        static void dsc_sort(int arr[], int x, int y);
};

void Sort_Element::asc_sort(int arr[], int x, int y){
    if(arr[x] > arr[y]){
        int t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }
}
void Sort_Element::dsc_sort(int arr[], int x, int y){
    if(arr[x] < arr[y]){
        int t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }
}
void bitonic_network(int arr[]){
   thread t[4];
   //step 1
   t[0] = thread(Sort_Element::asc_sort, arr, 0, 1);
   t[1] = thread(Sort_Element::asc_sort, arr, 4, 5);
   t[2] = thread(Sort_Element::dsc_sort, arr, 2, 3);
   t[3] = thread(Sort_Element::dsc_sort, arr, 6, 7);
   for(int i=0; i<4; i++){
       t[i].join();
   }
   #if 1
   //step 2
   t[0] = thread(Sort_Element::asc_sort, arr, 0, 2);
   t[1] = thread(Sort_Element::asc_sort, arr, 1, 3);
   t[2] = thread(Sort_Element::dsc_sort, arr, 4, 6);
   t[3] = thread(Sort_Element::dsc_sort, arr, 5, 7);
   for(int i=0; i<4; i++){
       t[i].join();
   }
   //step 3
   t[0] = thread(Sort_Element::asc_sort, arr, 0, 1);
   t[1] = thread(Sort_Element::asc_sort, arr, 2, 3);
   t[2] = thread(Sort_Element::dsc_sort, arr, 4, 5);
   t[3] = thread(Sort_Element::dsc_sort, arr, 6, 7);
   for(int i=0; i<4; i++){
       t[i].join();
   }
   //step 4
   t[0] = thread(Sort_Element::asc_sort, arr, 0, 4);
   t[1] = thread(Sort_Element::asc_sort, arr, 1, 5);
   t[2] = thread(Sort_Element::asc_sort, arr, 2, 6);
   t[3] = thread(Sort_Element::asc_sort, arr, 3, 7);
   for(int i=0; i<4; i++){
       t[i].join();
   }
   //step 5
   t[0] = thread(Sort_Element::asc_sort, arr, 0, 2);
   t[1] = thread(Sort_Element::asc_sort, arr, 1, 3);
   t[2] = thread(Sort_Element::asc_sort, arr, 4, 6);
   t[3] = thread(Sort_Element::asc_sort, arr, 5, 7);
   for(int i=0; i<4; i++){
       t[i].join();
   }
     //step 6
   t[0] = thread(Sort_Element::asc_sort, arr, 0, 1);
   t[1] = thread(Sort_Element::asc_sort, arr, 2, 3);
   t[2] = thread(Sort_Element::asc_sort, arr, 4, 5);
   t[3] = thread(Sort_Element::asc_sort, arr, 6, 7);
   for(int i=0; i<4; i++){
       t[i].join();
   }
   #endif

}

int main(){
    int arr[8];
    srand(time(0));

    for(int i=0; i<8; i++){
        arr[i] = rand() % 100;
        cout << arr[i] << ' ';
    }
    cout << endl;
    bitonic_network(arr);

    for(int i=0; i<8; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

}
