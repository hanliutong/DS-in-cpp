#include <iostream>
using namespace std;

template<class T> 
class List { 
public:
List(int MaxListSize = 10); //构造函数 
~List() {delete [] element;} //析构函数 
bool IsEmpty() const {return length == 0;} //判空
int Length() const {return length;} //返回当前长度
bool getValue(int k, T& x) const; //返回第k个元素至x中
int getPos(const T& x) const; // 返回x所在位置
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
int List<T>::getPos(const T& x) const{
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
bool List<T>::getValue(int k, T& x) const{
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
		cout << element[i] << "\t"; 
	}
	cout << endl;
};


bool Josephus(int n,int s, int m){
		if ( n<=0 || s<=0 || m<=0)
		{
			cout << "输入必须为正值！" << endl;
			return 0;
		}
		int x = 0;
		List<int> lst (n);
		List<int> Josephus (n);
		int j = 1;
		for (int i = 1; i <= n; ++i)
		{
			lst.Insert(i-1,i);
		}
		if (n<s){
			s = s%n ;
			cout << "警告 : 起始位置大于人数，将从第 "<<s<<" 人处起始\n\n";
		}
		cout <<"\t初始队列：\t";
		lst.travel();
		s = s-1;
		while (!lst.IsEmpty()){	
			printf("第%d次：\n",j );
			cout <<"\t当前队列：\t";
			lst.travel();
			lst.Delete((s+m-1)%lst.Length(),x);
			printf("\t从第%d人处起始，经过%d人，第%d人出列，他是：%d \n\n",s+1,m,(s+m-1)%(lst.Length()+1)+1,x);
			s = (s+m-1)%(lst.Length()+1);
			Josephus.Insert(j-1,x);
			j++;
		}
		cout <<"Josephus队列：\t";
		Josephus.travel();
		cout << endl << endl;
		return 1;

	};

	



int main()
{	
	
	Josephus(5,7,3);
	

	
	return 0;
	
} 
