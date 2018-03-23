#ifndef _LNKQUEUE_H
#define _LNKQUEUE_H
#include <iostream>
using namespace std;
#include "Link.h"

template <class T>		
class lnkQueue{	
private:Link<T> * front;
		Link<T> * rear;
		int size;
public: 
	lnkQueue();
	~lnkQueue();
	void clear();
	bool enQueue(T item);
	bool deQueue(T &item);
	bool getFront(T &item);

};

template <class T>
lnkQueue<T> :: lnkQueue(){
	size = 0;
	front = rear = NULL;
}

template <class T>
lnkQueue<T> :: ~lnkQueue(){
	clear();
}

template <class T>
void lnkQueue<T> :: clear(){
	while (front != NULL){
		rear = front;
		front = front -> next;
		delete rear;
	}
	rear = NULL;
	size = 0;
}

template <class T>
bool lnkQueue<T> :: enQueue(T item){
	if (front == NULL){
		front = rear = new Link<T>(item, NULL);
	}else{
		 
		rear -> next = new Link<T> (item, NULL);
		rear = rear ->next;
	}
		size ++ ;
		return 1;

	}


template <class T>
bool lnkQueue<T> :: deQueue(T &item){
	if (size == 0)
	{
		cout <<"队空不能出队" << endl;
		item = 0;
		return 0;
	}
	Link<T> *temp;
	item = front -> data;
	temp = front;
	front = front ->next;
	delete temp;
	if (front == NULL )
	{
		rear = NULL;
	}
	size --;
	return 1;

}

template <class T>
bool lnkQueue<T> :: getFront(T &item){
	if ( size == 0 )
	{
		cout <<"队空不能取队头" << endl;
		item = 0;
		return 0;
	}
	item = front ->data;
	return 1;

}
#endif //_LNKQUEUE_H
