#ifndef _GRAPHLX_H
#define _GRAPHLX_H
#include<queue>
//邻接表表示有向带权图

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
	// ~Graph( ){ delete [ ] Mark;	delete [ ] Indegree;	}
	//~Graph( ){ 	}

	int VerticesNum( ){	return numVertex; }
	bool IsEdge(Edge oneEdge){  //判断oneEdge是否是边
		if(oneEdge.weight >=0&&oneEdge.weight<65535
			&&oneEdge.to>=0)	return true;
		else return false;		}	};

struct listUnit{  //弧结点的数据域
	int vertex; //结点编号
	int weight; //权
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

class GraphLX: public Graph {  //邻接表类
	private:
		LList<listUnit> *graList;  //边链表头指针数组
	public: 
	GraphLX(int numVert):Graph(numVert){
		    graList = new LList<listUnit>[numVert]; 
	}
	int ToVertex(Edge e){
		return e.to;
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
			numEdge--; Indegree[to]--; 
			return;
		}	
	}
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
	// ~GraphLX( ){ delete [ ] Mark;	delete [ ] Indegree;	}
};
#endif //_GRAPHL_H