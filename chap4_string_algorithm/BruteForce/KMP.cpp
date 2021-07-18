#include <iostream>
#include <string>
#include "brute_force.cpp"
using namespace std;

class KMP : public BruteForce{
    private :
        static void initNext(const string& pattern, int table[], const int size);
    public :
        static void KMP(const string& pattern, const string& text, const int table[], const int size) const;        
};

void KMP::initNext(const string& pattern, int table[], const int size){
    
}
