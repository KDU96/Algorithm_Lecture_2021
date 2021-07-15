#include "stack.cpp"

int main(){
    MyStack<int> intStack(20);

    for(int i=0; i<20; i++)
        intStack.push(i);

    intStack.showAll();

    for(int i=0; i<20; i++)
        cout << intStack.pop() << endl;

    cout << endl;
}
