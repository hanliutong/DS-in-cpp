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

int main()
{
	int x = 0;
	arrQueue<int> QU_1(4);
	QU_1.enQueue(1);
	QU_1.enQueue(2);
	QU_1.enQueue(3);
	QU_1.enQueue(4);

	QU_1.getFront(x);
	cout << "get : " << x << endl;

	QU_1.deQueue(x);
	cout << "de 1 : " << x << endl;

	QU_1.deQueue(x);
	cout << "de 2 : "<< x << endl;

	QU_1.enQueue(5);
	
	QU_1.deQueue(x);
	cout << "de 3 : " << x << endl;

	QU_1.deQueue(x);
	cout << "de 4 : " << x << endl;

	QU_1.clear();
	QU_1.getFront(x);
	cout << x << endl;


	return 0;;
}