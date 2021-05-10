#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

template<typename T>
class MyQueue{
	private :
		T* data;
		int queueSize;
		int rear;
		int front;
	public :
		MyQueue(){}
		MyQueue(int size);
		~MyQueue(){delete[] data;}
		void insertq(T item);
		T deleteq();
		void setQueueSize(int size);
		bool isEmpty();
		bool isFull();
};
template<typename T>
MyQueue<T>::MyQueue(int size)
:queueSize(size){
	data = new T[size];
	rear = 0;
	front = 0;
}
template<typename T>
bool MyQueue<T>::isEmpty(){
	return (rear == front);
}
template<typename T>
bool MyQueue<T>::isFull(){
	return (front == (rear+1) % queueSize);
}
template<typename T>
void MyQueue<T>::insertq(T item){
	if(isFull()){
		cout << "queue is full\n" << endl;
		return;
	}
	data[rear] = item;
	rear = (rear+1) % queueSize;
}
template<typename T>
T MyQueue<T>::deleteq(){
	if(isEmpty()){
		cout << "queue is empty" << endl;
		exit(1);
	}
	T item = data[front];
	front = (front+1) % queueSize;
	return item;
}
template<typename T>
void MyQueue<T>::setQueueSize(int size){
	data = new T[size];
	queueSize = size;
	rear = 0;
	front = 0;
}

template<typename T>
class RandArray{
	private :
		T* data;
		int highestPosiionNum;
		int dataSize;
	public :
		RandArray(int size, int highestPosiionNum);
		~RandArray(){delete[] data;}
		void getData() const;
		void radixSort();
		void isSorted() const;
};
template<typename T>
RandArray<T>::RandArray(int size, int highestPosiionNum){
	this->highestPosiionNum = highestPosiionNum;
	dataSize = size;
	data = new T[size];
	int div = pow(10, highestPosiionNum-1);
	for(int i=0; i<dataSize; i++)
		data[i] = rand() % div;
}
template<typename T>
void RandArray<T>::getData() const{
	for(int i=0; i<dataSize; i++)
		cout << data[i] << " " ;
	cout << endl;
}
template<typename T>
void RandArray<T>::radixSort(){
	MyQueue<T> q[10];
	for(int i=0; i<10; i++)
		q[i].setQueueSize(dataSize+1);

	for(int i=0; i<highestPosiionNum; i++){
		for(int j=0; j<dataSize; j++){
			int div1 = pow(10, i+1);
			int div2 = pow(10, i);
			int index = data[j] % div1 / div2;
			q[index].insertq(data[j]);
		}
		int index = 0;
		for(int j=0; j<10; j++)
			while(!q[j].isEmpty())
				data[index++] = q[j].deleteq();
	}
}
template<typename T>
void RandArray<T>::isSorted() const{
	for(int i=0; i<dataSize-1; i++)
		if(data[i] > data[i+1]){
			cout << "sorting is failed" << endl;
			return;
		}
	cout << "sorting is success" << endl;
}
int main(){
	srand(time(0));
	RandArray<int> rndArr(10000, 6);
	
//	rndArr.getData();
	rndArr.radixSort();

	cout << endl;
	
//	rndArr.getData();
	rndArr.isSorted();
}
