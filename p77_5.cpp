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
class R_Lnk_QU{	
private:Link<T> * rear;
		//size = 0

public: 
	R_Lnk_QU();
	//~R_Lnk_QU();
	//void clear();
	bool enQueue(T item);
	bool deQueue(T &item);
	//bool getFront(T &item);

};

template <class T>
R_Lnk_QU<T> :: R_Lnk_QU(){
	rear = NULL;
}

template <class T>
bool R_Lnk_QU<T> :: enQueue(T item){
	if (rear == NULL)
	{
		rear = new Link<T> (item);
		rear -> next= rear;
		return 1;

	}else{
		Link<T> * new_link;
		new_link =new Link<T> (item, rear -> next);
		rear -> next = new_link;
		rear = new_link; 
		return 1;
	}
	
}

template <class T>
bool R_Lnk_QU<T> :: deQueue(T &item){
	/*if (rear == NULL)
	{
		cout <<"队空不能出队" << endl;
		item = 0;
		return 0;
	}*/
	Link<T> *temp;
	temp = rear -> next;
	item = temp -> data;
	rear ->next = temp -> next;
	delete temp;
	//if (front == NULL )
	//{	rear = NULL;}

	return 1;

}
 
int main()
{	
	int x;
	R_Lnk_QU<int> QU_5;
	QU_5.enQueue(1);
	QU_5.enQueue(2);
	QU_5.enQueue(3);
	QU_5.enQueue(4);

	QU_5.deQueue(x);
	cout << x <<endl;

	QU_5.deQueue(x);
	cout << x <<endl;

	QU_5.deQueue(x);
	cout << x <<endl;

	QU_5.enQueue(5);

	QU_5.deQueue(x);
	cout << x <<endl;

	QU_5.deQueue(x);
	cout << x <<endl;

	
	return 0;
}