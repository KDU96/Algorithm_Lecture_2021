#include <iostream>
using namespace std;

void counting_sort(int a[], int n, int m);  //n : a's size, m : count size

int main(){
    int a[9] = {0, 1, 2, 2, 1, 3, 4, 4, 1};
    counting_sort(a, 8, 4);
}

void counting_sort(int a[], int n, int m){
    int b[n];
    int i, j;
    for(i = 1; i<=m; i++)   count[i] = 0;
    for(i = 1; i<=n; i++)   count[a[i]]++;
    for(i = 2; i<=m; i++)   count[i] += count[i-1];
    for(i = n; i >= 1; i--){
        b[count[a[i]]] = a[i];
        count[a[i]]--;
    }
    for(i=1; i<= n; i++)
        a[i] = b[i];
};



