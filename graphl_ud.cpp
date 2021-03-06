#include <iostream>
using namespace std;
//邻接表表示无向带权图

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


struct listUnit{  //弧结点的数据域
	int vertex; //结点编号
	int weight; //权
};

template<class Elem> class Link{      //弧结点
	public: 	
		Elem element; //数据域类型参数ElemlistUnit
		bool Visited = 0;
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

class GraphL {  //邻接表类
	private:
		LList<listUnit> *graList;  //边链表头指针数组
	
	public: 
	GraphL(int numVert){
		    graList = new LList<listUnit>[numVert]; 
		}

	void setEdge(int from, int to, int weight) {  //设置边  3/4
		Link<listUnit> *t = graList[ from ].head; //边表首元
	   	while(t->next != NULL && t->next->element.vertex < to) 
			t =t->next; //确定<from,to>在边表中位置
		if ( t->next == NULL){ //不在边表中且应插在最后
			t->next =new Link<listUnit>;  //创建边
			t->next ->element.vertex =to;
			t->next->element.weight = weight;
			// numEdge++; Indegree[to]++; 
			setEdge(to,from,weight);//添加对应的边
			return;
		}

		if ( t->next->element.vertex == to){ //存在此边:改值
			if (t->next->element.weight == weight)//存在此边
				return;//退出（递归出口）
			 t->next->element.weight=weight;  
			 setEdge(to,from,weight);//修改对应的边
			 return;
		}

		if (t->next->element.vertex>to){ //不在边表中应插t后
			Link<listUnit>*other = t->next;  //新边后继,t为前驱
			t->next = new Link<listUnit>;//t后继为新边
			t->next->element.vertex = to;
			t->next->element.weight = weight;
			t->next->next = other;  //新边后继为other
			setEdge(to,from,weight);//添加对应的边
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
			delEdge(to,from);//删除对应的边
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
}; 

int main()
{
	cout << "Ah!" <<endl;
	GraphL a(6);
	a.setEdge(1,2,2);
	a.setEdge(1,4,4);
	a.setEdge(1,5,5);
	a.setEdge(3,1,3);
	a.delEdge(1,3);
	a.delEdge(4,1);
	Edge e1 = a.FirstEdge(1);
	Edge e2 = a.NextEdge(e1);
	Edge e3 = a.NextEdge(e2);
	cout 	<< e1.from << "\t"
			<< e1.to << "\t"
			<< e1.weight << endl;
	cout 	<< e2.from << "\t"
			<< e2.to << "\t"
			<< e2.weight << endl;
	cout 	<< e3.from << "\t"
			<< e3.to << "\t"
			<< e3.weight << endl;
	return 0;
}