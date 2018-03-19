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
		Link<T> head;
		int flag;
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
	
	head = Link<T>(-1,NULL);
	rear = &head;
	rear -> next = &head;
}

template <class T>
bool R_Lnk_QU<T> :: enQueue(T item){
	Link<T> * new_link;
	new_link =new Link<T> (item, rear -> next);
	rear -> next = new_link;
	rear = new_link;
	flag = 0;
		return 1;
	}

template <class T>
bool R_Lnk_QU<T> :: deQueue(T &item){
	if (flag ==  1)
	{
		cout << "err: this queue is empty" << endl;
		item = -1;
		return 0;
	}
	if (rear -> next -> next == rear)
	{
		flag =1;
	}
	Link<T> *temp;
	temp = rear -> next -> next;
	item = temp ->data;
	rear ->next -> next = temp -> next;
	delete temp;
	if (flag == 1)
	{
		rear = &head;
	}
	return 1;

}
 
int main()
{	
	int x;
	R_Lnk_QU<int> QU_5;
	QU_5.enQueue(1);
	QU_5.enQueue(2);
	QU_5.deQueue(x);
	cout << x<< endl;
	QU_5.deQueue(x);
	cout << x<< endl;
	QU_5.deQueue(x);
	cout << x<< endl;
	QU_5.deQueue(x);
	cout << x<< endl;
	QU_5.enQueue(3);
	QU_5.deQueue(x);
	cout << x<< endl;


	

	
	return 0;
}