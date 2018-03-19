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
}

int main()
{	
	
	List<int> list_A(10),list_B(10),list_C(10);
	//List<int> list_B(10);
	//List<int> list_C(10);

	for (int i = 0; i < 10; ++i)
	{
		list_A.Insert(i,i*10+1);
	}



	list_B.Insert(0,3);
	list_B.Insert(1,11);
	list_B.Insert(2,31);
	list_B.Insert(3,42);
	list_B.Insert(3,51);

	cout << " A: "; list_A.travel(); 
	cout << " B: "; list_B.travel();

	//int x;
	int pos_A = 0, pos_B = 0 ,pos_C = 0;
	int len_A = list_A.Length() , len_B = list_B.Length();
	int tmp_A = 0, tmp_B = 0;
	while ( pos_A < len_A && pos_B < len_B){
			list_A.Find(pos_A,tmp_A) ;
			list_B.Find(pos_B,tmp_B);

		     if ( tmp_A < tmp_B)
             {
                 pos_A++;
             } 
             else if(tmp_A > tmp_B)
             {          	
             	pos_B++;
             } 
             else
             {
                list_C.Insert(pos_C,tmp_A);
                pos_A++;
                pos_B++;
                pos_C++;
             }          
	}

	cout << " Length of \"C\"  = "<< list_C.Length() << endl;
	cout << " C: "; list_C.travel();
	//printf("%d\n",list_A );

	return 0;
	
} 
