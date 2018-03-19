#include <iostream>
using namespace std;

template <class T>
class arrStack{
private: 	int maxSize;
			int top_A, top_B;
			T *st;
public:	arrStack( int size);
		arrStack();
		~arrStack(); 
		void clear(); 
		bool push(int Cho,T item);
		bool pop(int Cho,T& item);		
		bool getTop(int Cho,T& item);		
};

template <class T>
arrStack<T>::arrStack(int size){
	maxSize = size;
	top_A = -1;
	top_B = maxSize;
	st = new T[size];
}

template <class T>
arrStack<T>::arrStack(){
	top_A = -1;
	top_B = maxSize;
}

template <class T>
arrStack<T>::~arrStack(){
	delete []st;
}

template <class T>
void arrStack<T>::clear(){
	top_A = -1;
	top_B = maxSize;
}

template <class T>
bool arrStack<T>::push(int Cho,T item){
	if (top_A == top_B - 1){
		cout << "err : This stack is full!" << endl;
		return 0;
	}
	if (Cho == 0)
	{
		top_A++;
		st[top_A] = item;
	}else{
		top_B--;
		st[top_B] = item;
	}
	return 1;
}

template <class T>
bool arrStack<T>::pop(int Cho , T& item){
	if ((top_A == -1 && Cho == 0)||(top_B == maxSize && Cho != 0)){
		item = -1;
		cout << "err : This stack is empty!" << endl;
		return 0;
	} 
		
	if (Cho == 0)
	{
		item = st[top_A];
		top_A--;
	}else{
		item = st[top_B];
		top_B++;
	}

	return 1;
}

template <class T>
bool arrStack<T>::getTop(int Cho, T& item){
	if ((top_A == -1 && Cho == 0)||(top_B == maxSize && Cho != 0)){
		item = -1;
		cout << "err : This stack is empty !" << endl;
		return 0;
	} 
		
	if (Cho == 0)
	{
		item = st[top_A];
	}else{
		item = st[top_B];
	}

	return 1;
}


int main()
{
	cout << "---test---" << endl;
	int x =0;
	arrStack<int> ST_1(3);
	ST_1.push(0,1);
	cout << ST_1.pop(0,x) << "<--bool  pop = "  << x << endl;
	cout << ST_1.pop(0,x) << "<--bool  pop = "  << x << endl;
	ST_1.push(1,2);
	ST_1.push(0,3);
	ST_1.push(0,4);
	ST_1.push(0,5);
	cout << ST_1.getTop(1,x) << "<--bool  top = "  << x << endl;
	cout << ST_1.pop(1,x) << "<--bool  pop = "  << x << endl;
	ST_1.push(1,6);
	ST_1.push(1,7);
	cout << ST_1.pop(1,x) << "<--bool  pop = "  << x << endl;
	cout << ST_1.getTop(1,x) << "<--bool  top = "  << x << endl;
	cout << ST_1.pop(1,x) << "<--bool  pop = "  << x << endl;
	ST_1.push(1,8);
	ST_1.clear();
	cout << ST_1.pop(1,x) << "<--bool  pop = "  << x << endl;
	return 0;
}