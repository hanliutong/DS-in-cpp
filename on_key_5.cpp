#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "MaxHeap.h"
using namespace std;
template <class Record>
void swap(Record Array[],int R ,int pivot){
	Array[R] = Array[R] + Array[pivot];
	Array[pivot] = Array[R] - Array[pivot];
	Array[R] = Array[R] - Array[pivot];
}
template <class Record>
void PrintRecord(Record Array[],int n){
	for (int i = 0; i < n; ++i)
	{
		cout << Array[i] << "\t";
	}cout << endl;cout << endl;
}

template <class Record > 			//分割后，轴值就位
int Partition( Record Array[ ], int left, int right){ 	
  int l = left;					// l为左指针
  int r = right;					// r为右指针
  Record  TempRecord = Array[ r ];      	//轴值存于临时变量
  while( l != r ){                                //l、r不断向中间移动，直到相遇
	while(Array[ l ]<=TempRecord && l<r )  l++; //l右移直至记录>轴值
	   if ( l<r ){   	//若l、r未相遇，错位元素换到右边空位
		  Array[ r ] = Array[ l ];   r--; }  //r指针左移一步再开始比
     while(Array[r]>= TempRecord &&  l<r )  r--; //r左移直至记录<轴值
	    if ( l<r ){ 	//若l、r未相遇，错位元素换到左边空位
		  Array[ l ] = Array[ r ]; l++;  }    //l指针右移一步再开始比
	}
	Array[ l ] = TempRecord;	 //把轴值回填到分界位置l上
	return l;				//返回分界位置l
}

template <class Record>
void QuickSort(Record Array[] , int L ,int R){
	if (R <= L) return;  //若子序列有0或1个记录,则不需排序
	int pivot = (L + R)/2 ; 	 //选择轴值
	swap( Array, pivot, R );   //分割前先将轴值放到数组末端
	pivot = Partition(Array, L, R); // 分割后枢轴就位	   
 	QuickSort(Array, L, pivot-1);  //对轴值左边子序列递归快排
 	QuickSort(Array, pivot +1, R);  //对轴值右边子序列递归快排
}

template <class Record>
void HeapSort( Record Array[ ], int n ) //堆排序HeapSort
{ 	MaxHeap<Record> max_heap=MaxHeap<Record>(Array,n); //初始建最大堆
	for (int i = 0; i < n; i++)
	{
		max_heap.Insert(Array[i]);
	}
	for( int i=0; i<n; i++) 	
	{	  //循环n-1次 找最大
		Array[n-1-i] = max_heap.RemoveMax( );
	}
}

//结点类
class Node{
public:
	int key;		//结点的关键码值
	int next;		//下一个结点在数组中的下标
};
//静态队列类
class StaticQueue{  
public:
	int head;
	int tail;
};

template <class Record>   //数组长n，d为排序码个数，r为基数
void RadixSort(Record* Array_o, int n, int d, int r) {
	int first=0;			// first指向静态链中第一个记录
	StaticQueue *queue; 			//存放r个桶的静态队列
	queue = new StaticQueue[r];
	Node Array[n];
	for (int i=0; i<n; i++){ 		 // 建链,初始next指下一记录
	    Array[i].next = i+1;
	    Array[i].key = Array_o[i];}
	Array[n-1].next = -1;				//链尾next为空
	for (int j=0; j<d; j++)  //对第j个排序码进行分配和收集共d趟
	{	Distribute(Array, first, j,  r, queue);
		Collect(Array, first, j,  r, queue);	}
	delete[ ] queue;
	AddrSort( Array, n, first );//O(n)整理，使按下标有序
	for (int i = 0; i < n; ++i)
	{
		Array_o[i] = Array[i].key;
	}
}

template <class Record>
void Distribute(Record* Array, int first, int i, int r, StaticQueue* queue){    //first静态链首记录,i为第i个排序码(个十百012),r基数
	int curr=first;
	for (int j=0; j<r; j++) queue[j].head=-1; //初始化r个队列
	while (curr != -1) {		//对整个静态链进行分配
	   int k=Array[curr ].key;	//取第i位排序码数字
	   for (int a=0;a<i; a++) 	k= k/r;  //个位:i=0,k不变
	   k=k%r;
		 // 把Array[curr]分配到第k个子序列中
	   if (queue[k].head == -1) // 若子序列为空Array[first]是首元
		 queue[k].head = curr;    
	   else Array[queue[k].tail].next = curr; //否则追加子序列尾
	   queue[k].tail = curr;                   //尾指针tail指向curr
	   curr = Array[curr].next; 	}      //继续分配下一个记录
}
template <class Record>
void Collect( Record* Array, int& first, int i, int r, StaticQueue* queue){	//A存待排记录，first为静态链首元，i为第i个排序码，r为基数
	int last, k=0;				//已收集到的最后一个记录
	while (queue[k].head == -1)  k++; 	// 找到第一个非空队列	
	first = queue[k].head;
	last = queue[k].tail;
	while (k<r-1){		//继续收集下一非空队,r-1是最后一个
	    k++; 			 //找到下一个非空队列
	    while (k<r-1 && queue[k].head==-1)  //当前队k空&不是最后
		k++;	 		
	    if (queue[k].head!= -1) {  		//首尾衔接	
		Array[last].next = queue[k].head;
		last = queue[k].tail;  }      // 此时最后一个记录为序列尾部记录
	}
	Array[last].next = -1; 	//收集完毕
}

template <class Record>
void AddrSort(Record* Array, int n, int first){ 
	int i, j = first; //j:待处理数据下标,第一次为first
	Record TempRec;
	for( i = 0; i < n-1; i++ ){ //每次处理第i大记录
		TempRec = Array[ j ]; //Array[ j ]现存第i大,暂存Temp; 
		Array[ j ] = Array[ i ]; //第i大现存Array[ j ],与Array[i]交换
		Array[ i ] = TempRec;
		Array[ i ].next = j; //交换后新主人(第i大)记录搬走人家(原array[i])新住址
		j = TempRec.next; //下一待处理数据下标j
		while( j <= i ) 
   //待处理处于已就位区域(0..i)说明老住户搬新居，按搬走前记录新址找
			j = Array[ j ].next; }
	}





int main()
{	
    // srand((unsigned)time(NULL));

	// cout << sizeof(int) << "\t\n";
	int n = 30000;
	cout << "n = " << n << endl;
	int a[n] = {0};
	int b[n] = {0};
	int c[n] = {0};
	for(int i=0;i<n;i++){
		a[i] =  rand()%n*2;
		b[i] = a[i];
		c[i] = a[i];
	}
    clock_t  start_a = clock();
	QuickSort(a,0,n-1);
	clock_t  end_a = clock();
	cout << "time_QuickSort = " << end_a - start_a << " ms"<<endl;//Θ(nlog n) 
	// PrintRecord(a,n);
	
	clock_t  start_b = clock();
	HeapSort(b,n);
	clock_t  end_b = clock();
	cout << "time_HeapSort = " << end_b - start_b << " ms" <<endl;//Θ(nlog n)
	// PrintRecord(b,n);

	clock_t  start_c = clock();
	RadixSort(c,n,6,9);
	clock_t  end_c = clock();
	cout << "time_RadixSort = " << end_c - start_c << " ms" <<endl;//Θ(d ·(n+r))
	// PrintRecord(c,n);
	
	return 0;
}

// oo000ooo