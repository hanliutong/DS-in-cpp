#include <iostream>
#include "time.h"
using namespace std;

void Random(int a[],int n, int m )  
{  
    int i=0;  
    srand( (unsigned)time( NULL ) );  
    while(i<n/2)  
    {  
        a[i++]=1+rand()%m;  
    }
    while(i<n)  
    {  
        a[i++]=-1-rand()%m;  
    }  
}  

template <class Record>
void swap(Record Array[ ], int i , int Smallest){
	Record temp = Array[i];
	Array[i] = Array[Smallest];
	Array[Smallest] = temp;
}

template <class Record>
void SelectSorter(Record Array[ ], int n){ //直接选择排序类
int i, j, Smallest;
for( i = 0; i<n-1; i++){   			//外层：n-1次
	Smallest = i;           //确定第i个，假设其就位(若错位则换)
	for( j = i+1; j<n; j++) {			 //内层：n-1-i次 比较
		if (Array[ j ] < Array[ Smallest ]) Smallest=j;//错位,记位置
	}
	if (i != Smallest)
		
		swap( Array, i, Smallest );
		
	} //使其就位 1次交换(3次移动)
}

void p236_14(int Array[], int n){
	int blue = 0, white = 0, red = 0 ;
	for (int i = 0; i < n; ++i)
	{
		switch (Array[i]){
		case 0: red++; break;
		case 1: white++; break;
		case 2: blue++; break;
		default:;
		}
	}
		red--;
		white+=red;
		blue+=white;
		while(blue >= 0){
			Array[blue] = 2;
			blue--;
		}
		while(white >= 0){
			Array[white] = 1;
			white--;
		}
		while(red >= 0){
			Array[red] = 0;
			red--;
		}
	}

void p236_13( int Array[ ],int n){ 
//源于分割函数Partition
  int l = 0;					// l为左指针
  int r = n;					// r为右指针
  int  TempRecord = 0;      	//轴值存于临时变量
  while( l != r ){              //l、r不断向中间移动，直到相遇
    while(Array[ l ]<=TempRecord && l<r )  l++; 
        if ( l<r ) { Array[ r ] = Array[ l ]; r--; } 
     while(Array[r]>= TempRecord &&  l<r )  r--; 
	    if ( l<r ) { Array[ l ] = Array[ r ]; l++; }
	}
} 


void p236_14_s(int Array[], int n){
	//Array中，0=红，1=白，2=蓝
	int white = 0, red = 0 ;//计数器
	for (int i = 0; i < n; ++i){//O(n)
		switch (Array[i]){//收集
		case 0: red++; break;
		case 1: white++; break;
		default:;
		}
		Array[i] = 2;
		//每个收集完了就先刷成蓝的
	}
		red--;
		white += red;
		while(white >= 0){//O(n)
			//从0到r+w-1位置都先刷成白的
			Array[white] = 1;
			white--;
		}
		while(red >= 0){//O(n)
			//从0到r-1位置都刷成红的
			Array[red] = 0;
			red--;
		}
}


int main(int argc, char const *argv[])
{
	int n = 5000;
	int Array[n];
	Random(Array,n,3);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << Array[i] << "\t";
	// } cout <<endl;
	clock_t start_time=clock();
	{
	SelectSorter(Array,n);
	}
	clock_t end_time=clock();
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << Array[i] << "\t";
	// } cout <<endl;
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	return 0;
}