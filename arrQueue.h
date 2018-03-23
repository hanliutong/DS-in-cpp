#ifndef _ARRQUEUE_H
#define _ARRQUEUE_H
#include <iostream>
using namespace std;

template <class T>		
class arrQueue{	
private:	int mSize;
			int front; 
			int rear;
			T* qu;
public: 
	arrQueue(int Size);
	~arrQueue();
	void clear();
	bool enQueue(T item);
	bool deQueue(T &item);
	bool getFront(T &item);

};

template <class T>
arrQueue<T> :: arrQueue(int Size){
	qu = new T[Size];
	mSize = Size;
	front = rear = 0;
}

template <class T>
arrQueue<T> :: ~arrQueue(){
	delete []qu;
}

template <class T>
void arrQueue<T> :: clear(){
	front = rear = 0;
}

template <class T>
bool arrQueue<T> :: enQueue(T item){
	if ( (rear + 1) % mSize == front)
	{
		cout <<"队满不能入队" << endl;
		item = 0;
		return 0;
	}
	qu[rear] = item;
	rear = (rear + 1) %mSize ;
	return 1;

}

template <class T>
bool arrQueue<T> :: deQueue(T &item){
	if (rear == front)
	{
		cout <<"队空不能出队" << endl;
		item = 0;
		return 0;
	}
	item = qu[front];
	front = (front + 1) %mSize ;
	return 1;

}

template <class T>
bool arrQueue<T> :: getFront(T &item){
	if (rear == front)
	{
		cout <<"队空不能取队头" << endl;
		item = 0;
		return 0;
	}
	item = qu[front];
	return 1;

}
#endif //_ARRQUEUE_H