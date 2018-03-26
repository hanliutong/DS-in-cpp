#ifndef _LNKSTACK_H
#define _LNKSTACK_H
#include <iostream>
using namespace std;
#include "Link.h"
template <class T>
class lnkStack{
private:Link<T> * top;
		int size;
public:	lnkStack();
		~lnkStack();
		void clear();
		bool push(T item);
		bool pop(T& item);
		bool getTop(T& item);
};

template <class T>
lnkStack<T>::lnkStack(){
	top = NULL;
	size =0;
}

template <class T>
lnkStack<T>::~lnkStack(){ clear(); }

template<class T>
void lnkStack<T> :: clear(){
	while (top != NULL){
		Link<T> *t_del = top;
		top = top -> next;
		delete t_del;
		}
	size =0;
}

template<class T>
bool lnkStack<T> :: push(T item){
	//cout << "\t" << item <<" is pushing\t" << "size = " << size << endl;
	Link<T> *q = new Link<T> (item, top);
	top = q ;
	size ++;
	return 1;
}

template<class T>
bool lnkStack<T> :: pop(T& item){
	//cout << "before size = "<< size << endl;
	if ( size == 0)
	{
		cout << "栈空不能出栈" << endl;
		item = 0;
		return 0;
	}
	item = top -> data;
	
	Link<T> *t_del = top;
	top = top -> next;
	delete t_del;
	size --;
	//cout << "after size = "<< size << endl;
	return 1;
	
}


template<class T>
bool lnkStack<T> :: getTop(T& item){
	if ( size == 0)
	{
		cout << "栈空不能读取"<<endl;
		item = 0;
		return 0;
	}
	
	item = top -> data;
	return 1;
}

#endif //_LNKSTACK_H