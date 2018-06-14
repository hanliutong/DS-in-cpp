#ifndef _MAXHEAP_H
#define _MAXHEAP_H
#include <iostream>
using namespace std;

template <class T>
class MaxHeap  		//最小堆ADT定义
{private:
	T* heapArray;		//存放堆数据的数组
	int CurrentSize;	//当前堆中元素数目
	int MaxSize;		//堆所能容纳的最大元素数目
	void BuildHeap( );	//建堆
public:
	MaxHeap(T Array[ ],const int n);//n最大元素数
     ~MaxHeap( ){delete [ ]heapArray;}; //析构函数
	bool isEmpty(  );
	bool isLeaf(int pos) const; //如果是叶结点，返回true		
	int LeftChild(int pos) const; 	//返回左孩子位置
	int RightChild(int pos) const; 	//返回右孩子位置
	int Parent(int pos) const; 		// 返回父结点位置	
	bool Remove(int pos, T& node); 	// 删除给定下标的元素
	bool Insert(const T& newNode);	//向堆中插入新元素
	T  RemoveMax( ); 		//从堆顶删除最小值
	void SiftUp(int position); 
         //从position向上开始调整，使序列成为堆
	void SiftDown(int left);
         //筛选法函数，参数left表示开始处理的数组下标
	void show(){
		for (int i = 0; i < CurrentSize; i++)
		{
			cout << "\tArray[" << i << "] = " << heapArray[i] <<endl;
		}cout<< endl;
	}
};

template<class T>
MaxHeap<T>::MaxHeap(T Array[ ],const int n)
{	if(n<=0)		return;
	CurrentSize=0;						
	MaxSize=n; 			//初始化堆容量为n
	heapArray=new T[ MaxSize]; //创建堆空间
	BuildHeap( );  			//建堆
}

template<class T>
void MaxHeap<T>::BuildHeap( )
{  //从最后一个父结点至根逐一筛选
	for (int i=CurrentSize/2-1; i>=0; i--) 
	SiftDown(i); 					
} 

template<class T>
T MaxHeap<T>::RemoveMax( )	{ //从堆顶删除最小值
		if(CurrentSize==0) {//空堆
			cout <<"CurrentSize = 0"<<endl;
			exit(1);}
		else{  
			T temp = heapArray[0];
			heapArray[0] = heapArray[--CurrentSize];
			heapArray[CurrentSize] = temp;
			if(CurrentSize >1)         // <=1不用调整  
		 	SiftDown(0); 	//从堆顶开始筛选
		 	// show();
			return heapArray[CurrentSize];	}	
}

template <class T>
void MaxHeap<T>::SiftDown(int left)
{	int i = left;  //标识父结点i
	int j = 2*i+1;     //标识关键值较小的子结点		
	T	temp= heapArray[i]; //保存父结点
while( j < CurrentSize){
  if(( j<CurrentSize-1)&&( heapArray[j]<heapArray[j+1]))
		j++;  //j指向数值较大的子结点
  if(temp<heapArray[j]){   //父<较大孩子
		heapArray[i]=heapArray[j];  //小子替换父
		i=j;     	j=2*j+1;  }  //父向下继续与孩子比
  else break;			}
 heapArray[i]=temp;				
}

template <class T>
bool MaxHeap<T>::Insert(const T& newNode)
//向堆中插入新元素newNode
{
	if(CurrentSize==MaxSize)	//if堆空间已经满
		return 0;
	heapArray[CurrentSize]= newNode; //追加至尾
	SiftUp(CurrentSize); //向上调整
	CurrentSize++; //长+1
	return 1;
}

template<class T>
int MaxHeap<T>::Parent(int pos) const  
{	return (pos-1)/2; 	//返回pos的父结点位置
}

template<class T>
void MaxHeap<T>::SiftUp(int position)  //(参ppt-p70插入例)
{		//从position向上开始调整，使序列成为堆
	int temppos=position;
	T temp=heapArray[temppos];  //temp暂存被调结点值
	while(( temppos>0 )&& ( heapArray[Parent(temppos)]<temp ))   
                                     //有父&&父>子：父子交换
	{	heapArray[temppos]=heapArray[Parent(temppos)];
		temppos=Parent(temppos);	}  //继续向上找父
	heapArray[temppos]=temp; 	//子最终就位
}

#endif //_MAXHEAP_H