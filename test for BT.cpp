#include "lnkStack.h"
#include "BinaryTreeNode.h"
// #include "BinaryTreeNode.h"
// #include "BinaryTree.h"
#include <iostream>
using namespace std;


template <class T>
class BinaryTree { // C++定义, 没有具体规定存储方式
private:
	BinaryTreeNode<T>*  root; //二叉树根结点指针
public:
	BinaryTree(){root=NULL;} 	   //构造函数
	BinaryTree( BinaryTreeNode<T>* RootNode){ root=RootNode;} //改写的构造函数
	//~BinaryTree( ) {DeleteBinaryTree(root);}//析构函数
	~BinaryTree( ){};
	bool isEmpty() const;     	   //判二叉树是否为空树
	BinaryTreeNode<T>* Root(){return root;}//返二叉树根
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);//返回current结点的父结点
	BinaryTreeNode<T>* LeftSibling(
	BinaryTreeNode<T>* current); //返current结点左兄弟
	BinaryTreeNode<T>* RightSibling(
    BinaryTreeNode<T>* current); //返current右兄弟
	// void CreateTree(const T& elem, BinaryTree<T>& leftTree, 	BinaryTree<T>& rightTree);
	void CreateTree(BinaryTreeNode<T> &rootNode, BinaryTreeNode<T> &leftTree, BinaryTreeNode<T> &rightTree);
               // 已知根、左子树、右子树，构造二叉树
	void CreateTree(BinaryTreeNode<T>* rootNode, BinaryTreeNode<T>* leftTree, BinaryTreeNode<T>* rightTree);
	void PreOrder(BinaryTreeNode<T>* root); //前序周游bt
	void InOrder(BinaryTreeNode<T>* root); //中序周游
	void PostOrder(BinaryTreeNode<T>* root); //后序周游
	void LevelOrder(BinaryTreeNode<T>* root); //按层次周游
	void DeleteBinaryTree(BinaryTreeNode<T>* root);//删bt
	int height();//返回树的高度（只有一个结点的树高是1）
	int height(BinaryTreeNode<T>* node) ;
	bool search(BinaryTree<T> tree,T k);
	bool search(BinaryTreeNode<T>* root , T k);
	// bool search(BinaryTreeNode<T> * root,T k);
};

template <class T>
bool BinaryTree<T>::isEmpty()const{
	if (root == NULL)
	{
		return 1;
	}
	return 0;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current){
	lnkStack<BinaryTreeNode<T>*> aStack;
	BinaryTreeNode<T>* pointer = root;
		// cout << "pointer -> left = "<<pointer -> left <<endl;
		// cout << "pointer -> right = " << pointer -> right << endl;
		// cout << "current = " << current <<endl;
	if (pointer == NULL || current == NULL)
		{
			cout << "输入/根节点为空，无法找到父节点。" <<endl;
			return root ;
		}
	BinaryTreeNode<T>* x;
	aStack.push(NULL);
	while(pointer){

		if (pointer -> left == current || pointer ->right == current)
		{return pointer;}
		else
			{
			if (pointer -> right != NULL)
				aStack.push(pointer->right);
			if (pointer -> left != NULL)
				pointer = pointer -> left;
			else{
				aStack.pop(x);
				pointer = x;
				}
			}
	}
	return root;
}
template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root){ //前序周游bt
	lnkStack<BinaryTreeNode<T>*> aStack;
	BinaryTreeNode<T>* pointer = root;
	BinaryTreeNode<T>* x;
	aStack.push(NULL);
	while(pointer){
		cout << pointer -> info ;
		if (pointer -> right != NULL)
			aStack.push(pointer->right);
		if (pointer -> left != NULL)
			pointer = pointer -> left;
		else{
			aStack.pop(x);
			pointer = x;
		}
	}
	cout << endl;
}

// template <class T>
// void BinaryTree<T>::CreateTree(const T& elem, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree){
// 	root = new BinaryTreeNode<int> (elem);
// 	root.setLeftchild(leftTree);
// 	root.setRightchild(rightTree);
// }

template <class T>
void BinaryTree<T>::CreateTree(BinaryTreeNode<T> &rootNode, BinaryTreeNode<T> &leftTree, BinaryTreeNode<T> &rightTree){
	root = &rootNode;
	root -> left = &leftTree;
	root -> right = &rightTree;
}

template <class T>
void BinaryTree<T>::CreateTree(BinaryTreeNode<T>* rootNode, BinaryTreeNode<T>* leftTree, BinaryTreeNode<T>* rightTree){
	root = rootNode;
	root -> left = leftTree;
	root -> right = rightTree;
}

template <class T>
int BinaryTree<T>::height(){ //求树高（基于前序周游）
	if (root == NULL) { return 0;}
	int count = 1;//当前高度
	int max = 0;
	lnkStack<BinaryTreeNode<T>*> aStack;//存储右子树的栈
	lnkStack<int> countStack;//存储右子树对应高度的栈
	BinaryTreeNode<T>* pointer = root;//工作指针指向根节点
	aStack.push(NULL);//监测哨NULL
	countStack.push(1);//NULL对应的高度
	while(pointer){//基于前序周游
		if (pointer -> right != NULL){
			aStack.push(pointer->right);
			countStack.push(count+1);//右子所在高度入栈
		}
			
		if (pointer -> left != NULL){
			pointer = pointer -> left;
			count ++;//高度+1
		}
		else{
			
			aStack.pop(pointer);//取栈中右子
			countStack.pop(count);
			//高度更新为取出的右子所在高度
		}
		if (count > max) max = count;
	}
	return max;
	cout << endl;
}

template<class T>
bool BinaryTree<T>::search(BinaryTree<T> tree , T k){
	BinaryTreeNode<T> * root = tree.Root();
	BinaryTree<T> tree_l;
	bool r = 0;
	bool l = 0;
	if (root -> info== k)	return 1;
	else{
		if (root -> right){
			tree.CreateTree(root -> right , root -> right -> left , root -> right -> right);
			r = search(tree,k);
		}
		if (root -> left){
			tree.CreateTree(root -> left , root -> left -> left , root -> left -> right);
			l = search(tree,k);
		}
		return (r||l);
	}
}

template<class T>
bool BinaryTree<T>::search(BinaryTreeNode<T>* root , T k){
	bool r = 0;
	bool l = 0;
	if (root -> info== k)	return 1;
	else{
		if (root -> right){
			r = search(root -> right , k);
		}
		if (root -> left){
			l = search(root -> left , k);
		}
		return (r||l);
	}
}


// template<class T>
// bool BinaryTree<T>:: search(BinaryTreeNode<T> * root,T k){
// 	bool l = 0;
// 	bool r = 0;
// 	if (root -> info == k)
// 	{
// 		return 1;
// 	}
// 	else{
// 		if (root -> left)
// 			l = search(root -> left , k);
// 		if (root -> right)
// 			r = search(root -> right , k);
// 		return (r||l);
// 	}
// }

template <class T>
int BinaryTree<T>:: height(BinaryTreeNode<T>* node) 
    {	int l_height = 0;
    	int r_height = 0;
        if (node == NULL)
            return 0;
        else
        {
            l_height = height(node->left);
            r_height = height(node->right);

            if (l_height > r_height)
                return (l_height + 1);
             else
                return (r_height + 1);
        }
    }

int main()
{
	
	BinaryTreeNode<int> a,b,c,d,e;
	a.setValue(1);
	b.setValue(2);
	c.setValue(3);
	d.setValue(4);
	e.setValue(5);
	cout << "a = " << &a <<endl;
	cout << "b = " << &b <<endl;
	cout << "c = " << &c <<endl;
	cout << "d = " << &d <<endl;
	cout << "e = " << &e <<endl;
	BinaryTree<int> T1;
	BinaryTree<int> T2(&d);
	T2.CreateTree(a,b,c);
	c.setRightchild(&d);
	b.setLeftchild(&e);
	// d.setRightchild(&e);
	cout << T2.Parent(&d) << endl;
	T2.PreOrder(&a);	
	cout << T2.height() << endl;
	cout << T2.search(T2,5) <<endl;
	cout << T2.height(&a)<<endl;
	cout << T2.search(T2.Root(),4) << endl;
	return 0;
}
