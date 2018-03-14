#include <iostream>
using namespace std;

template <class T>
class arrStack{
private: 	int maxSize;
			int top;
			T *st;//存放元素的数组
public:	arrStack( int size);//构造函数-->给定长度的实例
		arrStack();//创建一个顺序栈实例
		~arrStack(); // 析构函数
		void clear(); // 清空
		bool push(T item);//入栈函数
		bool pop(T& item);		//出栈函数
		bool getTop(T& item);		//取栈顶
};

template <class T>
arrStack<T>::arrStack(int size){
	maxSize = size;
	top = -1;
	st = new T[size];
}

template <class T>
arrStack<T>::arrStack(){
	top = -1;
}

template <class T>
arrStack<T>::~arrStack(){
	delete []st;
}

template <class T>
void arrStack<T>::clear(){
	top = -1;
}

template <class T>
bool arrStack<T>::push(T item){
	if (top == maxSize - 1){
		cout << "err:This stack is full" << endl;
		return 0;
	}
	top++ ;
	st[top] = item;
	return 1;
}

template <class T>
bool arrStack<T>::pop(T& item){
	if (top == -1){
		item = -1;
		return 0;
	} 
		

	item = st[top];
	top--;
	return 1;
}

template <class T>
bool arrStack<T>::getTop(T& item){
	if (top == -1) {
		item = -1;
		return 0;
	}
	
	item = st[top];
	return 1;
}



int main()
{
	cout << "---test---" << endl;
	int x =0;
	arrStack<int> ST_1(2);
	ST_1.push(1);
	cout << ST_1.getTop(x) << "<--bool  top = "  << x << endl;
	ST_1.push(2);
	ST_1.push(3);
	cout << ST_1.getTop(x) << "<--bool  top = "  << x << endl;
	cout << ST_1.pop(x) << "<--bool  top(pop) = "  << x << endl;
	cout << ST_1.getTop(x) << "<--bool  top = "  << x << endl;
	ST_1.clear();
	cout << ST_1.getTop(x) << "<--bool  top = "  << x << endl;
	return 0;
}