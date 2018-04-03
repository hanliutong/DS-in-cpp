#include <iostream>
using namespace std;
class test_c
{
public:
	test_c(){};
	~test_c(){};
	void test(int &x){
	data = x;
	point = &x;
	cout << point <<endl;
	cout << data << endl;
	}
	int getData(){return data;};
	int* getPoint(){return point;};
private:
 	int data;
	int * point; 
};


int main(int argc, char const *argv[])
{
	test_c a;

	int one =1;
	cout << &one << endl;
	a.test(one);
	cout << a.getPoint() <<endl;
	cout << a.getData() << endl;
	return 0;
}




template <class T>
int Tree<T>::count(TreeNode<T>* root){
	int lc = 0;
	int rs = 0;
	if(root){
		if (root -> pChild){
			lc = 1;
			lc += count(root->pChild)
		}
		if (root -> pSibling)
		{
			rs = 1;
			rs += count(root -> pSibling)
		}
	}else
	return lc + rs;
}

int getNum(Tree<T> &tree){
	if (tree.isEmpty())
	return 0;
	return 1 + tree.count(tree.getRoot()); 
}

