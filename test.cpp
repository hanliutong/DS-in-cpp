#include<iostream>
#include"GraphLX.h"

using namespace std;
int col(int x,int y){
	return y*y + x*x + 7*x;
}

int SI(int x,int y){
		cout << "x = " << x << "\t y = " << y << endl;
		int FO = col(x,y);
		int FY = col(x,y+1);
		int FX = col(x+1,y);
		if (FO > FY && FY > FX ) SI(x+2,y);
		if (FO > FX && FX > FY ) SI(x,y+2);
		if (FO < FX && FX < FY ) SI(x,y-2);
		if (FO < FY && FY < FX ) SI(x-2,y);
		if (FY < FO && FO < FX ) SI(x-2,y+2);
		if (FX < FO && FO < FY ) SI(x+2,y-2);
		return 0;
}



int show (int x ,int y){
	cout << col(x,y) << "\t";
	cout << col(x+1,y) << "\t";
	cout << col(x,y+1) << "\t" <<endl;
	if (col(x+1,y) > col(x,y+1)) return 1;
	if (col(x+1,y) < col(x,y+1)) return 2;
	return 0;

}

bool canFinish (GraphLX& G){
	int vNum = G.VerticesNum();
	for(int i=0; i<vNum; i++){
		G.Mark[i]=UNVISITED;}//初始化标记数组（G的域）
  	queue<int> Q;     //初始化队列，由标准库
	for(int i=0; i<vNum; i++)  { 
	if(G.Indegree[i]==0) Q.push(i);  
	}
    while(!Q.empty()){
 	    int V=Q.front();      
 	    Q.pop();
        G.Mark[V]=VISITED;
        cout << V << "\t";
    	for(Edge e=G.FirstEdge(V);G.IsEdge(e);e=G.NextEdge(e)){
	    	G.Indegree[G.ToVertex(e)]--;
	        if(G.Indegree[G.ToVertex(e)]==0)
			Q.push(G.ToVertex(e));
		}    
	}
	cout << "\n";
 	for(int i=0; i<vNum; i++){
 		if(G.Mark[i]==UNVISITED)
     		return 0;
	}
	return 1;
}

int main(){



GraphLX G(5);
G.setEdge(1,2,1);
G.setEdge(2,3,1);
G.setEdge(1,4,1);
G.setEdge(4,3,1);
G.setEdge(4,2,1);

cout << canFinish(G);

	return 0;
} 