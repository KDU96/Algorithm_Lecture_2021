#include "stack.h"

template<typename T>
MyStack<T>::MyStack(int s)
:size(s), top(-1)
{
    mystack = new T[size];
}
template <typename T>
MyStack<T>::~MyStack(){
    delete[] mystack;
}
template <typename T>
bool MyStack<T>::isFull() const{
    return (top == size -1);
}

template <typename T>
bool MyStack<T>::isEmpty() const{
    return (top == -1);
}
template <typename T>
bool MyStack<T>::push(T item){
    if(isFull()){
        cout << "stack is full" << endl;
        return false;
    }
    mystack[++top] = item;
    return true;
}
template <typename T>
T MyStack<T>::pop(){
    if(isEmpty()){
        cout << "stack is empty" << endl;
        exit(1);
    }
    return mystack[top--];
}
template <typename T>
void MyStack<T>::showAll() const{
    for(int i=0; i<=top; i++)
        cout << mystack[i] << endl;
    cout << endl;
}
