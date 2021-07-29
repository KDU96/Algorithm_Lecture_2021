#include <iostream>
#include <vector>
using namespace std;

int sum_of_1and2(int n){
    int i;
    vector<int> f(n+1, -1);
    f[1] = 1;
    f[2] = 2;
    if(n > 2){
        for(int i=3;i<=n; i++)
            f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main(){
    cout << "sum : " << sum_of_1and2(4) << endl;
    cout << "sum : " << sum_of_1and2(5) << endl;
}
