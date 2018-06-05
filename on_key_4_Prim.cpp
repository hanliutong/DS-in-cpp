#include <iostream>
#include <queue>
#include "GraphL.h"
using namespace std;
const int INF = 655;
class Dist{
public:
	int index = 0;//顶点编号
	int length = 0;
	int pre = 0;
};

void ShowMst(Edge *MST,int n){
	cout << "form\tto\t\tweight\n";
	for (int i = 0; i < n; ++i)
	{
		cout << MST[i].from << "\t\t " << MST[i].to << "\t\t " << MST[i].weight  << endl;
	}
}

int minVertex(Graph& G, Dist * &D){ //D数组中选最小
	int i, v;
	for( i=0; i<G.VerticesNum( ); i++)
		if ( G.Mark[i]==UNVISITED){
			v = i; break;     }  //v:首个未访问过顶点,作“选最小”初值
	for ( i=0; i<G.VerticesNum( ); i++)
		if ( G.Mark[i]==UNVISITED && D[i].length<D[v].length)
			v = i;  //存最小
	return v;						
}

void AddEdgetoMST(Edge edge, Edge* &MST , int n){
	// cout << edge.from  << "\t " << edge.to << "\t" << edge.weight<< endl;
	MST[n] = edge;
	// cout << MST[n].from << "\t" << MST[n].to << "\t" << MST[n].weight  << endl;
}

void Prim(GraphL& G, int s, Edge* &MST ) {
	int MSTtag = 0; 	//最小支撑树边计数器
	MST=new Edge[G.VerticesNum()-1];
	Dist *D;
	D = new Dist[G.VerticesNum( )];
//初始化Mark数组、距离数组D
   for(int i=0; i<G.VerticesNum(); i++){ 
		G.Mark[i]=UNVISITED; 
		D[ i]. index = i;
		D[ i]. length = INF;
		D[ i].pre = s;				}
	D[s].length = 0;
	G.Mark[ s ] = VISITED; //开始顶点首先被标记
	 int v=s;
	 for ( int i= 0; i<G.VerticesNum( )-1; i++) {
	  if ( D[v].length==INF) 
          return;  // i与v无边,非连通,没有最小生成树
for(Edge e= G.FirstEdge(v);G.IsEdge(e);e=G. NextEdge(e))
	    if ( G. Mark[e.to]==UNVISITED&&
		(D[e.to].length>e.weight )){ //v与To权更小
		D[e.to].length = e.weight; //改D
		D[e.to].pre = v;	}
  v = minVertex( G, D);  // 调用“D数组中选最小”函数
	G.Mark[v]=VISITED; //v标记为访问过
	Edge edge(D[v].pre, D[v].index, D[v].length ); //建边
	AddEdgetoMST( edge, MST, MSTtag++); //入MST		
	}
} 


void DFS(GraphL& G, int V){       //深度优先搜索算法实现
     G.Mark[V]= VISITED;  //访问顶点V并标记其标志位
     cout << V << "\t";              //访问V
for(Edge e=G. FirstEdge(V);G.IsEdge(e);e=G. NextEdge(e))         
              //递归周游与V邻接未访问过的顶点
          if ( G.Mark[e.to]== UNVISITED)
      	    DFS(G, e.to);   
}

void BFS(GraphL& G, int V)  { 
   using std::queue;     queue<int> Q;  // //初始化队列 
    G.Mark[V]= VISITED; 
    cout << V <<"\t";     //先访问
    Q.push(V); 	//再入队 
    while(!Q.empty())    //如果队列仍然有元素
{   int V=Q.front( );   Q.pop( );       //出队	
    //将与该点相邻的每一个未访问点都访问完入队
 for(Edge e=G.FirstEdge(V);G.IsEdge(e);e=G.NextEdge(e))
   {      if(G.Mark[e.to]== UNVISITED) {   
			 G.Mark[e.to]=VISITED;
           cout << e.to <<"\t";;
		 Q.push(e.to);      }	}  }   }


int main()
{
	//———————初始化图————————
	int n=7;
	GraphL G(n);
	G.setEdge(0,1,20);
	G.setEdge(0,4,1);
	G.setEdge(4,5,15);
	G.setEdge(3,5,12);
	G.setEdge(1,3,4);
	G.setEdge(1,2,6);
	G.setEdge(2,6,2);
	G.setEdge(3,6,8);
	G.setEdge(5,6,10);
	//———————初始化图完成—————
	Edge* MST;
	Prim(G,0,MST);
	ShowMst(MST,G.VerticesNum()-1);

	for (int i = 0; i < n; i++)
	{
		G.Mark[i] = UNVISITED;
	}
	cout << "DFS : "; DFS(G,0); cout << endl;

	for (int i = 0; i < n; i++)
	{
		G.Mark[i] = UNVISITED;
	}
	cout << "BFS : "; BFS(G,3); cout << endl;
	return 0;
}