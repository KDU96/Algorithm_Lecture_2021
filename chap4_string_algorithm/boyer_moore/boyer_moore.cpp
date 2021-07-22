#include <iostream>
#include <string>
#include <vector>
using namespace std;

char* skipTbl(const string& pattern){
    int M = pattern.length()+1;
    char* tbl = new char[M];
    tbl[M-1] = 0;
    for(int i=0; i<M; i++)
        tbl[i] = pattern[M-2-i];
    return tbl;
}
int skip(const char& ch, const char skip[], int size){
    for(int i=0; i<size-1; i++)
        if(skip[i] == ch)   return i;
    return size-1;
}
int MisChar(const string& pattern ,const string& text){
    char *tbl = skipTbl(pattern);
    int i, j, k;
    for(i = pattern.length()-1, j = pattern.length()-1; j >= 0; i--, j--){
         while(text[i] != pattern[j]){
         k = skip(text[i], tbl, pattern.length());
         if(pattern.length() - j > k)    i = i + pattern.length() - 1;
          else                            i += k;
          if(i >= text.length()){
                delete[] tbl;
                return text.length();
                
            }
            j = pattern.length() - 1;
     }
        
    }
        delete[] tbl;
        return i + 1;
    
}

int main(){
    string pattern = "ATION";
    string text = "ONION NATATOO ATAA VATION";

    cout << "loc : " << MisChar(pattern, text) << endl;
    
}