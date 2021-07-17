#include <iostream>
using namespace std;
void quick_sort(int a[], int l, int r){
    int i, j, m, v;
    if(r-l > 1){
        // a[l], a[r-1], a[r] -- smail, middle, large
        m = (l + r) / 2;
        if(a[l] > a[m]) swap(&a[l], &a[m]);
        if(a[l] > a[r]) swap(&a[l], &a[r]);
        if(a[m] > a[r]) swap(&a[m], &a[r]);
        swap(&a[r-1], &a[m]);

        v = a[r-1]; i = l;  j = r-1;
        
        while(1){
            while(a[++i] < v);
            while(a[--j] > v);
            if(i >= j)  break;
            swap(&a[i], &a[j]);
        }
        swap(&a[i], &a[r-1]);
        quick_sort(&a[l], &a[i-1]);
        quick_sort(&a[i+1], &a[r]);
    }
    else if(a[l] > a[r]) swap(&a[l], &a[r]);
}
void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
