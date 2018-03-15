#include <iostream>
using namespace std;

template <class T>		//结点定义、2个构造函数
class Link{				//结点Link
public: T 	data;	//数据域
    Link<T>	*next;	//指针域，自引用型类型

    Link( T info,  Link<T> *nextValue = NULL) {
        data = info;
        next = nextValue;			}

    Link(Link<T> *nextValue) {
        next = nextValue;			}
    Link(){
        T *next;
    }
};

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

int main()
{
	int x = 0;
	lnkQueue<int> QU_1;
	QU_1.enQueue(1);
	QU_1.enQueue(2);
	
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
	cout << "here" << endl;
	QU_1.getFront(x);
	cout << x << endl;


	return 0;;
}