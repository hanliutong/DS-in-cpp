#include <iostream>
#include "GraphLX.h"
using namespace std;
const int INF = 655;
//使用Dijkstra算法求单元最短路径
//多次调用Dijkstra求点对点路径
class Dist{
public:
	int index = 0;//顶点编号
	int len = 0;
	int pre = 0;
};



void print_Dist(Dist D[], int count){
	cout << "idx" << "\t";
	for (int i = 0; i < count; ++i)
	{
		cout << D[i].index << "\t";
	}
	cout << endl;

	cout << "len" << "\t";
	for (int i = 0; i < count; ++i)
	{
		cout << D[i].len << "\t";
	}
	cout << endl;

	cout << "pre" << "\t";
	for (int i = 0; i < count; ++i)
	{
		cout << D[i].pre << "\t";
	}
	cout << endl;
}

int min_Dist (Dist array[],int n,GraphLX G){//返回最小权值的点索引
	int min =n-1;
	for (int i = 0; i < n; ++i)
	{
		if (G.Mark[i] == UNVISITED && array[i].len < array[min].len)
			min = array[i].index;
	}
	return min;
}//O(n)

void Dijkstra (GraphLX G, int s, Dist* &D){//s为初始顶点编号
	D = new Dist[G.numVertex];
	for (int i = 0; i < G.numVertex; ++i)
	{
		D[i].index = i;
		D[i].len = INF;
		D[i].pre = s;
	}
	D[s].len = 0;
	//------以上均为初始化------
	G.Mark[s] = VISITED;
	int v = s;//v：新加入s集合的点
	for (int i = 0; i < G.numVertex-1; ++i)//循环n-1次即可得到结果
	{
		for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{//修改权值：
			if (e.weight + D[v].len < D[e.to].len )
			{
				D[e.to].len = e.weight + D[v].len;
		 		D[e.to].pre = e.from;
			}
		}//O(e)
		
		v = min_Dist(D, G.numVertex, G);//取最小:O(n)
		G.Mark[v] = VISITED;
		cout << v <<endl;//输出被选的点
	}

	for (int i = 0; i < G.numVertex; ++i)
	{
		G.Mark[i] = UNVISITED;
	}
}//O[n*(e+n)]

void getPath(GraphLX G, int n, int* M[]){
	//初始化n*n矩阵
	for (int i = 0; i < n; ++i)
	{
		Dist* D;
		Dijkstra(G,i,D);
		for (int j = 0; j < n; ++j)
		{
			M[i][j] = D[j].len;
		}
	}
}
void print_Matrix(int* M[], int n){
	cout << "___MATRIX___"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << M[i][j] << "\t";
		}cout << endl;
	}cout << endl;
}

int main(){
//———————初始化图————————
	int n=5;
	GraphLX G(n);
	G.setEdge(0,1,10);
	G.setEdge(0,4,100);
	G.setEdge(0,3,30);
	G.setEdge(1,2,50);
	G.setEdge(2,4,10);
	G.setEdge(3,2,20);
	G.setEdge(3,4,60);

//———————单元最短————————
	Dist* D;
	Dijkstra(G,0,D);
	print_Dist(D,n);
//———————点对点最短————————
	int **M;
	M = new int *[n];
	for (int i = 0; i < n; ++i)
		M[i] = new int [n];//初始化矩阵

	getPath(G,n,M);
	print_Matrix(M,n);

	return 0;
}