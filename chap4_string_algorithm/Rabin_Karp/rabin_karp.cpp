#include <iostream>
#include <string>
#include <limits>
#define MAX_INT 3354393
using namespace std;

int index(char ch){
    if(ch == 32)    return 0;
    else            return ch - 64;
}

int RabinKarp(string pattern ,string text){
    int dM = 1;
    int h1 = 0, h2 = 0;
    int M = pattern.length();
    int N = text.length();
    int d = 32;
    int i;

    for(i=0; i < M; i++)    dM *= d;
    for(i=0; i<M; i++){
        h1 = (h1 * d + index(pattern[i])) % MAX_INT;
        h2 = (h2 * d+ index(text[i])) % MAX_INT;
    }
    for(i=0; h1 != h2; i++){
        h2 = (h2 + d * MAX_INT - dM * index(text[i])) % MAX_INT;
        h2 = (h2 * d + index(text[i + M])) % MAX_INT;
        if(i > N - M + 1)   return N;
    }
    cout << "success" << endl;
    return i;
}
int main(){
    string text = "  ATION";
    string pattern = "ATION";

    cout << "loc : " << RabinKarp(pattern, text) << endl;
}