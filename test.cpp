#include <iostream>
using namespace std;
int INF = 65525;
int min_int (int array[],int n){
	int min =INF;
	for (int i = 0; i < n; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}


class Dist{
public:
	int index = 0;//顶点编号
	int len = 0;
	int pre = 0;
};

int main()
{	
	int n = 5;
	int **M;
	M = new int *[n];
	for (int i = 0; i < n; ++i)
	{
		M[i] = new int [n];
	}
	M[0][0] = 1;
	



	return 0;
}