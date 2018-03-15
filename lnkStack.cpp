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
    Link(){        T *next;    };
};

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
	Link<T> *q = new Link<T> (item, top);
	top = q ;
	size ++;
	return 1;
}

template<class T>
bool lnkStack<T> :: pop(T& item){
	cout << "before size = "<< size << endl;
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
	cout << "after size = "<< size << endl;
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

int main()
{	/*
	int x = 0;
	lnkStack<int> lST_1;
	lST_1.push(1);
	//lST_1.push(2);
	lST_1.pop(x);
	cout << x << endl ;
	lST_1.getTop(x);
	cout << x << endl ;
	return 0;
	*/

}