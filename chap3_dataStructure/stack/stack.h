#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
class MyStack{
	private :
		T* mystack;
        int size;
		int top;
        bool isFull() const;
        bool isEmpty() const;
	public :
        MyStack(int s);
        ~MyStack();
        bool push(T item);
        T pop();
        void showAll() const;
};
#endif

		

