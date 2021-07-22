#include <iostream>
#include <string>
using namespace std;

int* initNext(const string& pattern){
    int *next = new int[pattern.length()];
    int i, j;
    next[0] = -1;
    for(i=0, j=-1; i < pattern.length(); i++, j++){
        next[i] = j;
        while((j >= 0) && pattern[i] != pattern[j]){
            j = next[j];
        }
    }
    return next;
}
int KMP(const string& pattern, const string& text){
    int* next = initNext(pattern);
    int i, j;
    for(i=0, j=0; j < pattern.length(), i < text.length(); i++, j++){
        while(j >=0 && text[i] != pattern[j])
            j = next[j];
    }
    delete[] next;
    if(j == pattern.length()){
        cout << "the pattern is matched" << endl;
        return i - pattern.length();
    }
    else                        return i;
}

int main(){
    string pattern = "10100111";
    string text = "0101010201010102101010111110100111";
    cout << "location : " << KMP(pattern, text) << endl;
}