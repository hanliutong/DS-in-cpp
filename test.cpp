#include <iostream>
#include <stack>
#include <queue>
using namespace std;
enum Mark{UNVISITED,VISITED};
class Edge{	//边
 public: 
	int from , to , weight; //起点、终点、权
 	Edge() {
		from = -1;
		to = -1;
		weight = 0;
	}
	Edge(int f, int t, int w) {
		from = f;
		to = t;
		weight = w;
	}
};
class Graph{
	public: int numVertex;  int numEdge;  //顶点个数,边数
		 int *Mark;	int *Indegree;  //访问数组,入度数组
	Graph( int numVert ){
		numVertex = numVert;
		numEdge =0;
		Indegree =new int[ numVertex ];
		Mark = new int[ numVertex ];
		for( int i=0; i<numVertex; i++){
			Mark[i]=UNVISITED; 	Indegree[i]=0;}	}
	~Graph( ){ delete [ ] Mark;	delete [ ] Indegree;	}
	//~Graph( ){ 	}
	int VerticesNum( ){	return numVertex; }
	bool IsEdge(Edge oneEdge){  //判断oneEdge是否是边
		if(oneEdge.weight >=0&&oneEdge.weight<65535
			&&oneEdge.to>=0)	return true;
		else return false;		}	};




struct listUnit{  //弧结点的数据域
	int vertex; 
	int weight; 
};

template<class Elem> class Link{      //弧结点
	public: 	
		Elem element; //数据域类型参数ElemlistUnit
		Link *next;	      //指针域
  		Link(const Elem& elemval, Link *nextval=NULL){
  			element = elemval;
  			next =nextval; 
  		}
  		Link( Link *nextval = NULL){ next = nextval; }
};

template <class Elem> class LList {   //链表头指针类
	public: 
		Link<Elem> *head;   
		LList(){	head = new Link<Elem>( );	}//附加头结点	
};

class Graphl: public Graph{  //邻接表类
	private:
		LList<listUnit> *graList;  //边链表头指针数组
	
	public: 
	Graphl(int numVert):Graph(numVert) {
		    graList = new LList<listUnit>[numVert]; 
		}
	// ~Graphl(){cout<<"~"<<endl;};
	Edge FirstEdge( int oneVertex ) {
		Edge myEdge;
		myEdge.from = oneVertex;
		Link<listUnit> *temp = graList[oneVertex].head;
		if (temp->next!= NULL){
			myEdge.to =temp ->next->element.vertex;
			myEdge.weight =temp->next->element.weight;
		}
		return myEdge;		
	}

	Edge NextEdge( Edge preEdge){
		Edge myEdge;
		myEdge.from = preEdge.from;
		Link <listUnit> *temp =graList[ preEdge.from].head;
		while( temp->next!=NULL&&
			temp->next->element.vertex<=preEdge.to )
			temp = temp->next;
		if (temp->next!=NULL){
			myEdge.to = temp->next->element.vertex;
			myEdge.weight = temp->next->element.weight; }
		return myEdge;
	}

	void setEdge(int from, int to, int weight) {  //设置边  3/4
		Link<listUnit> *t = graList[ from ].head; //边表首元
	   	while(t->next != NULL && t->next->element.vertex < to) 
			t =t->next; //确定<from,to>在边表中位置
		if ( t->next == NULL){ //不在边表中且应插在最后
			t->next =new Link<listUnit>;  //创建边
			t->next ->element.vertex =to;
			t->next->element.weight = weight;
			numEdge++; Indegree[to]++; 
			return;
		}

		if ( t->next->element.vertex == to){ //存在此边:改值
			 t->next->element.weight=weight;  
			 return;
		}

		if (t->next->element.vertex>to){ //不在边表中应插t后
			Link<listUnit>*other = t->next;  //新边后继,t为前驱
			t->next = new Link<listUnit>;//t后继为新边
			t->next->element.vertex = to;
			t->next->element.weight = weight;
			t->next->next = other;  //新边后继为other
			numEdge++; Indegree[to]++; 
			return;
		}
	}

	void delEdge( int from ,int to){
		Link <listUnit> *temp = graList[from].head; //指前驱
		while( temp->next!=NULL&& 
			temp->next->element.vertex<to) 
				temp =temp->next;
		if (temp->next==NULL) return; //到边表尾未见<from,to>
		if (temp->next->element.vertex > to) return; //边表中未见
		if (temp->next->element.vertex == to){
			Link<listUnit> *other=temp->next->next; //指后继
			delete temp->next;  
			temp->next = other ;  //维护逻辑关系
			numEdge--; Indegree[ to]--; 
			return;
		}	
	}
	int ToVertex(Edge e){
		return e.to;
	}
};


bool TopsortbyQueue(Graphl& G) {
	int v = G.VerticesNum();
	for(int i=0; i<v; i++){
		G.Mark[i]=UNVISITED;}   //初始化标记数组
  		queue<int> Q;     //初始化队列     
	for(int i=0; i<v; i++)  { 
     if(G.Indegree[i]==0) Q.push(i);  } //入度为0顶点入队
     while(!Q.empty()){      //如果队列非空
 	    int V=Q.front();      Q.pop(); //选  出队
        G.Mark[V]=VISITED; //访问顶点改标记	
    for(Edge e=G.FirstEdge(V);G.IsEdge(e);e=G.NextEdge(e))
      { G.Indegree[G.ToVertex(e)]--;  //删 弧头入度减-1
        if(G.Indegree[G.ToVertex(e)]==0) //若减至0: 入队 
		Q.push(G.ToVertex(e));   }    }
 for(int i=0; i<v; i++)  {
     if(G.Mark[i]==UNVISITED)
     	return 0;
 }
	return 1;
}




class Solution {
public:

    

};
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graphl a(numCourses);
        for (int i = 0; i<prerequisites.size();i++){
            a.setEdge(prerequisites[i].first,prerequisites[i].second,1);
        }

        bool x = TopsortbyQueue(a);
        return x;
    }

int main()
{
	// cout << "Ah!" <<endl;
	// Graphl a(5);
	// a.setEdge(1,2,2);
	// a.setEdge(1,4,4);
	// a.setEdge(1,5,5);
	// a.setEdge(1,3,3);
	// a.setEdge(3,1,3);
	// // a.delEdge(1,3);
	// // a.delEdge(1,4);
	// Edge e1 = a.FirstEdge(1);
	// Edge e2 = a.NextEdge(e1);
	// Edge e3 = a.NextEdge(e2);
	// cout 	<< e1.from << "\t"
	// 		<< e1.to << "\t"
	// 		<< e1.weight << endl;
	// cout 	<< e2.from << "\t"
	// 		<< e2.to << "\t"
	// 		<< e2.weight << endl;
	// cout 	<< e3.from << "\t"
	// 		<< e3.to << "\t"
	// 		<< e3.weight << endl;
	// int temp = TopsortbyQueue(a);
	// cout << temp <<endl;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(1,0));
	prerequisites.push_back(make_pair(0,1));
	cout << prerequisites.size() <<endl;
	cout << canFinish(2,prerequisites)<<endl;
	return 0;
}

