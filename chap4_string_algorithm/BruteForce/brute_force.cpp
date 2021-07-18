#include <iostream>
#include <string>
using namespace  std;

class BruteForce{
    public :
        static int bruteForce(const string& pattern, const string& text);
};

int BruteForce::bruteForce(const string& pattern, const string& text){
    int patternLength = pattern.length();
    int textLength = text.length();
    int i, j;
    for(i=0, j=0; i < patternLength, j < textLength; i++, j++){
        if(pattern.at(i) != text.at(j)){
            j = j - i;
            i = -1;
        }
    }
    if(i == patternLength) return j - patternLength;
    else return textLength;
}

int main(){
    string pattern = "10100111";
    string text = "100110101010110100101010100111";

    cout << BruteForce::bruteForce(pattern, text) << endl;
}