#include <iostream>
using namespace std;

template<class T> 
class List { 
public:
List(int MaxListSize = 10); //构造函数 
~List() {delete [] element;} //析构函数 
bool IsEmpty() const {return length == 0;} //判空
int Length() const {return length;} //返回当前长度
bool Find(int k, T& x) const; //返回第k个元素至x中
int Search(const T& x) const; // 返回x所在位置
bool Delete(int k, T& x);//删除第k个元素并将其返回到x中
bool Insert(int k, const T& x);//在第k个元素之前插入x
void travel();//遍历整个表（输出）
private:
int length; //当前长度
int MaxSize; // 总长度
T *element; // 一维动态数组
};

template<class T> 
List<T>:: List(int MaxListSize){
	length = 0;
	MaxSize = MaxListSize;
	element = new T[MaxListSize];
};
template<class T>
bool List<T>::Insert(int k, const T& x){
	if (k<0 || k>MaxSize)
	{
		cout << "err:illegal k" << endl;
		return 0;
	}
	for (int i = length - 1; i >= k; --i)
	{
		element[i+1] = element[i];
	}
	length++;
	element[k]=x;
	return 1;
};
template<class T>
bool List<T>::Delete(int k, T& x){
	if (k<0 || k>=length)
	{
		cout << "err:illegal k" << endl;
		x = -1;
		return 0;
		exit (1);
	}
	x = element[k];
	for (int i = k; i < length; ++i)
	{
		element[i] = element[i+1];
	}
	length--;
	return 1;

};
template<class T>
int List<T>::Search(const T& x) const{
	int flag = 0;
	for (int i = 0; i <= length; ++i)
	{
		if (element[i] == x)
		{
			flag = 1;
			return i;
			break;
		}
		if (flag ==1)
		{
			break;
		}
	}
	if (flag == 0)
	{
	return -1;
	}
};
template<class T>
bool List<T>::Find(int k, T& x) const{
	if (k>=0 && k < length)
	{
		x = element[k];
		return 1;
	}
	else 
	{
		x = -1;
		return 0;
	}
};

template<class T>
void List<T>::travel(){
	for (int i = 0; i < length; ++i)
	{
		cout << element[i] << " "; 
	}
	cout << endl;
};

int main()
{	
	
	List<int> l_int_1 (5);
	l_int_1.Insert(0,10);
	l_int_1.Insert(1,20);
	l_int_1.Insert(2,30);
	l_int_1.Insert(3,40);
	int x;
	cout << "Length = "<< l_int_1.Length() << endl;
	cout << l_int_1.Find(4,x) << endl << x<< endl;
	l_int_1.Delete(1,x);

	cout << "Length = "<< l_int_1.Length() << endl;
	cout << "x = " << x << endl;
	//printf("%d\n",l_int_1 );
	int b[10] = {1,2,3,4,5};
	//cout << int (l_int_1) << endl << b[1] << endl;
	
	return 0;
	
} 
