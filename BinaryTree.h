#ifndef _BINARYTREE_
#define _BINARYTREE_
#include <iostream>
#include "lnkStack.h"
#include "BinaryTreeNode.h"
#include <cmath>
#include <string>
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
    void CreateTree(BinaryTreeNode<T>* rootNode){root = rootNode;}
	// void CreateTree(const T& elem, BinaryTree<T>& leftTree, 	BinaryTree<T>& rightTree);
	void CreateTree(BinaryTreeNode<T> &rootNode, BinaryTreeNode<T> &leftTree, BinaryTreeNode<T> &rightTree);
               // 已知根、左子树、右子树，构造二叉树
	void CreateTree(BinaryTreeNode<T>* rootNode, BinaryTreeNode<T>* leftTree, BinaryTreeNode<T>* rightTree);
	void CreateTree(const T info, BinaryTree<T> *l, BinaryTree<T> *r);
	void PreOrder(BinaryTreeNode<T>* root); //前序周游bt 根左右
	void InOrder(BinaryTreeNode<T>* root); //中序周游 	左根右
	void PostOrder(BinaryTreeNode<T>* root); //后序周游	左右跟
	void LevelOrder(BinaryTreeNode<T>* root); //按层次周游
	void DeleteBinaryTree(BinaryTreeNode<T>* root);//删bt
	int height();//返回树的高度（只有一个结点的树高是1）
	int height(BinaryTreeNode<T>* node) ;
	bool search(BinaryTree<T> tree,T k);
	bool search(BinaryTreeNode<T>* root , T k);
	void print();
	int SetPos(BinaryTreeNode<T> * pointer, int Pos, int Width);//返回最大值
	int SetRow(BinaryTreeNode<T> * pointer,int Row);//返回最大值
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
		cout << pointer -> info << " ";
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

template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root){ //后序周游bt
	if (root -> left)
	{
		PostOrder(root -> left);	
	}
	if (root -> right)
	{
		PostOrder(root -> right);	
	}
	cout << root -> info << " ";
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root){ //中序周游bt
	if (root -> left)
	{
		InOrder(root -> left);	
	}
	cout << root -> info << " ";
	if (root -> right)
	{
		InOrder(root -> right);	
	}
}

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
void BinaryTree<T>::CreateTree(const T info, BinaryTree<T> *l, BinaryTree<T> *r)
    {
        BinaryTreeNode<T> *l_c, *r_c;
        if (l != NULL)
        {
            l_c = l->Root();

        } else
        {
            l_c = NULL;

        }
        if (r != NULL)
        {
            r_c = r->Root();

        } else
        {
            r_c = NULL;

        }
        root = new BinaryTreeNode<T>(info, l_c, r_c);
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
	if (root -> value() == k)	return 1;
	else{
		if (root -> rightchild()){
			r = search(root -> rightchild(), k);
		}
		if (root -> leftchild()){
			l = search(root -> leftchild(), k);
		}
		return (r||l);
	}
}

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

template <class T>
int BinaryTree<T>::SetPos(BinaryTreeNode<T> * pointer,int Pos, int Width){
	int offset = Width/(2*(pointer->row+2));
	int temp = Pos + offset;
	pointer -> pos = Pos;
	if (pointer -> left)
	{
		SetPos(pointer -> left, Pos - offset, Width);
	}
	if (pointer -> right)
	{
		temp = SetPos(pointer -> right, Pos + offset, Width);
	}
	return temp;
}

template <class T>
int BinaryTree<T>::SetRow(BinaryTreeNode<T> * pointer,int Row){
	pointer -> row = Row;
	int l = 0, r = 0;
	if (pointer -> left)
	{
		l = SetRow(pointer -> left, Row + 1);
		l++;
	}
	if (pointer -> right)
	{
		r = SetRow(pointer -> right, Row + 1);
		r++;
	}
	if (r>l)
	{
		return r;
	}
	return l;
}

template <class T>
void BinaryTree<T>::print(){
	const int Row = SetRow(root,0);
	const int Pos = SetPos(root,70,70);
	// cout << "Pos = " << Pos << endl;
	// cout << "Row = " << Row << endl;
	string str[Pos + 1][Row + 1];
	string line[Pos + 1][Row + 1];
	// string str[Pos+1][Row+1] ={""};
	// string line[Pos+1][Row+1] ={""};
	int line_start = 0, line_end = 0;
	// int cnt[Row] = {0};
	int cnt[Row];
	for (int i = 0; i < Row; i++)
	{
		cnt[i] = 0;
	}
	for (int i = 0; i <= Pos; ++i)
	{
		for (int j = 0; j <= Row; ++j)
		{
			str[i][j] =" ";
			line[i][j] =" ";
		}
	}

	lnkStack<BinaryTreeNode<T>*> aStack;
	BinaryTreeNode<T>* pointer = root;
	BinaryTreeNode<T>* x;
	aStack.push(NULL);
	while(pointer){
		str[pointer->pos-cnt[pointer->row]][pointer->row] = "(" + pointer -> info +")";
		cnt[pointer->row]+=4;
		// cout << "Pos = " << pointer->pos <<"\tRow = " << pointer->row  <<"\tinfo = " << pointer -> info << "isLeaf: " << pointer->isLeaf() << endl;
		if (pointer -> right != NULL){
			line_end = pointer -> right -> pos;
			aStack.push(pointer->right);
		}
		if (pointer -> left != NULL){
			line_start = pointer -> left -> pos;
			for(int i = line_start+1; i<=line_end+1; ++i){
				line[i][pointer->row] = "_";
			}
			line[pointer->pos][pointer->row] = "|";
			pointer = pointer -> left;
			
		}
		else{
			aStack.pop(x);
			pointer = x;
		}
	}

	for (int j = 0; j <= Row; ++j)
	{
		for (int i = 0; i <= Pos; ++i)
		{
			cout << str[i][j];
		}
		cout << endl;
		for (int i = 0; i <= Pos; ++i)
		{
			cout << line[i][j];
		}
		cout << endl;
	}

}

#endif //_BINARYTREENODE_