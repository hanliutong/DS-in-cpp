//二叉树结点
#ifndef _BINARYTREENODE_
#define _BINARYTREENODE_
#include <iostream>
// #include "BinaryTree.h"
template <class T>
class BinaryTree;
template <class T>
class BinaryTreeNode {
friend class BinaryTree<T>;
friend void TreeNode2In(BinaryTreeNode<string>*root,bool flag);
  //便于BinaryTree访问BinaryTreeNode私有成员
  private:
  			T  info; 	      //二叉树结点数据域
  			BinaryTreeNode<T>* left; //指向左子树的指针；
  			BinaryTreeNode<T>* right; //指向右子树的指针；
  			int pos = 0;//该结点的位置，由树中的SetPos函数维护；
  			int row = 0;//该结点的行，由树中的SetRow函数维护；
  public:  
	// template <typename X> friend class BinaryTree;
	BinaryTreeNode( );	      //缺省构造函数
    BinaryTreeNode(const T& ele); //给定数据的构造函数
  	BinaryTreeNode(const T& ele , BinaryTreeNode<T>* l , BinaryTreeNode<T>* r); //给定结点值和左右子树的构造函数
	T  value( ) const; //返回当前结点的数据
	BinaryTreeNode<T>*  leftchild() const;    //返左孩子指针
	BinaryTreeNode<T>*  rightchild() const; //返右孩子指针
	void setLeftchild(BinaryTreeNode<T>* l) ;
	 //设置当前结点的左子树
	void setRightchild(BinaryTreeNode<T>* r) ;
	//设置当前结点的右子树
	void  setValue(const T& val);
	//设置当前结点的数据域
	bool  isLeaf() const; 
    //判定当前结点是否为叶结点,若是返回true
	BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node);
	 //重载赋值操作符=
	// friend class BinaryTree; 
};

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(){
	// info = 0;
	left = right = NULL;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele){
	info = ele;
	left = right = NULL;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele , BinaryTreeNode<T>* l , BinaryTreeNode<T>* r){
	info = ele;
	left = l;
	right = r;
}
template <class T>
T BinaryTreeNode<T>::value()const{
	return info;
}

template <class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::leftchild()const{
	return left;
}

template <class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::rightchild()const{
	return right;
}

template <class T>
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* l){
	left = l;
}

template <class T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* r){
	right = r;
}

template <class T>
void BinaryTreeNode<T>::setValue(const T& val){
	info = val;
}

template <class T>
bool  BinaryTreeNode<T>::isLeaf()const{
	if (right == NULL && left == NULL)
	{
		return 1;
	}
	return 0;
}

#endif //_BINARYTREENODE_
