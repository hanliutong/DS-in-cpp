//
// Created by Hanliutong on 2018/3/21.
//
#include "List.h"
bool Josephus(int n,int s, int m){//定义函数Josephus(元素个数，起始位置，间隔) 
	//检查输入合法性
	if ( n<=0 || s<=0 || m<=0)
	{
		cout << "错误 ： 输入必须为正值！" << endl;
		return 0;
	}
	if (n<s){
		s = s%n ;
		if (s == 0) s = n;
		cout << "警告 : 起始位置大于人数，将从第 "<<s<<" 人处起始\n\n";
	}
	//变量初始化
	int x = 0;//每次出列的人
	List<int> lst (n);//当前队列
	List<int> Josephus (n);//Josephus队列
	int j = 1;//次数
	//队列初始化
	for (int i = 1; i <= n; ++i)
	{
		lst.Insert(i-1,i);
	}
	//输出初始队列
	cout <<"\t初始队列：\t";
	lst.travel();
	s = s-1;//由第s人转换为数组中的s位置
	while (!lst.IsEmpty()){	//不断出列直到队列空
		printf("第%d次：\n",j );
		cout <<"\t当前队列：\t";
		lst.travel();//输出当前队列
		//由s位置开始经过m人，即经过（s+m-1）个元素，对队列长度取模实现循环
		lst.Delete((s+m-1)%lst.Length(),x);//出列元素由x带回
		printf("\t从第%d人处起始，经过%d人，第%d人出列，他是：%d \n\n",
			s%(lst.Length()+1)+1 , m , (s+m-1)%(lst.Length()+1)+1 , x);

		s = (s+m-1)%(lst.Length()+1);//s位置更新为刚刚出列元素的位置

		Josephus.Insert(j-1,x);//在Josephus队列中加入刚刚出列的元素
		j++;//次数加1
	}
	//输出Josephus队列
	cout <<"Josephus队列：\t";
	Josephus.travel();
	cout << endl << endl;
	return 1;
	};

int main()
{	
	Josephus(10,3,3);//Josephus(元素个数，起始位置，间隔) 

	return 0;
} 

