#include <iostream>
#include "TreeNode.h"
using namespace std;
template <class T>
class Tree{
private:
	TreeNode<T>* root;
public:
	Tree(TreeNode<T>* pRoot);
	~Tree(){};
	int count(TreeNode<T>* root);
	int getNum(TreeNode<T>* tree);
	// TreeNode<T>* pChild(TreeNode<T>* current){return current -> pChild;};
	// TreeNode<T>* pSibling(TreeNode<T>* current){return current -> pSibling;};
	TreeNode<T>* getRoot();
	bool isEmpty();

};

template<class T>
Tree<T>::Tree(TreeNode<T>* pRoot){
	root = pRoot;
}
template<class T>
bool Tree<T>::isEmpty(){
	// cout << "isEmpty：root = " << root <<endl;
	if (root) return 0;
	else return 1;
}

template<class T>
TreeNode<T>* Tree<T>::getRoot(){
	return root;
}

template <class T>
int Tree<T>::count(TreeNode<T>* root){//pp.159/6:getNum调用的的递归函数
	int lc = 0;
	int rs = 0;
	if(root){
		if (root -> pChild){
			lc = 1;
			lc += count(root->pChild);
		}
		if (root -> pSibling){
			rs = 1;
			rs += count(root -> pSibling);
		}
	}
		return lc + rs;
}

template <class T>
int Tree<T>::getNum(TreeNode<T>* tree){//pp.159/6 ：输入一个树，求树的节点数目
	if (tree == NULL)
	return 0;
	return count(tree) + 1;
	//"+ 1"因为存在根节点 
}

int main(int argc, char const *argv[])
{
	TreeNode<int> a,b,c,d,e,f;
	a.setValue(1); 
	b.setValue(2); 
	c.setValue(3); 
	d.setValue(4); 
	e.setValue(5); 
	f.setValue(6); 

	Tree<int> T1(&a);
	a.setClild(&b);
	b.setSibling(&c);
	c.setSibling(&d);
	c.setClild(&e);
	e.setSibling(&f);

	// cout << T1.pChild(&a) << endl;
	// cout << T1.pSibling(&a) << endl;
	cout << T1.count(&a) <<endl;
	cout << T1.isEmpty()<<endl;
	cout << T1.getNum(&a) <<endl;


	return 0;
}