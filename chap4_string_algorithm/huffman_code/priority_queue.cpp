#include <iostream>
#include <queue>
#include <functional>
#include <list>
//#include <cstdio>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;

    pq1.push(3);
    pq1.push(1);
    pq1.push(4);
    pq1.push(1);
    pq1.push(5);
    pq1.push(9);

    pq2.push(3);
    pq2.push(1);
    pq2.push(4);
    pq2.push(1);
    pq2.push(5);
    pq2.push(9);

    while(!pq1.empty()){
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    while(!pq2.empty()){
        cout << pq2.top() << ' ';
        pq2.pop();
    }

}