
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