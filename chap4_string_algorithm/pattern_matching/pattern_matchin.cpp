#include <iostream>
#include <string>
#include <deque>
using namespace std;

#define     scan    -1
#define     TRUE    1
#define     FALSE   0


int main(){
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    dq.push_front(5);
    
    deque<int>::iterator iter;

    dq.pop_front();

    for(iter = dq.begin(); iter != dq.end(); iter++)
        cout << *iter << ' ';

    cout << endl;
}

