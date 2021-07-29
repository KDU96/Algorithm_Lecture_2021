#include <iostream>
using namespace std;

int fib(int n){//bottom-top method
    int i, f[n+1];
    f[0] = 0;
    if(n > 0){
        f[1] = 1;
        for(i=2; i<=n; i++)
            f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main(){
    cout << fib(5) << endl;
}