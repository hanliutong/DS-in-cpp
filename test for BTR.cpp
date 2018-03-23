#include <iostream>
using namespace std;

template <class T>
class BinaryTreeNode {	
  friend class BinaryTree; //便于BinaryTree访问BinaryTreeNode私有成员
  private:	T  info; 	      //二叉树结点数据域
  			BinaryTreeNode<T>* left; //指向左子树的指针；
  			BinaryTreeNode<T>* right; //指向右子树的指针；
  			//BinaryTreeNode<T>* head;//指向根节点的头指针；
  public:  
	BinaryTreeNode( );	      //缺省构造函数
    BinaryTreeNode(const T& ele); //给定数据的构造函数
  	BinaryTreeNode(const T& ele , BinaryTreeNode<T>* l , BinaryTreeNode<T>* r); //给定结点值和左右子树的构造函数
	T  value( ) const; //返回当前结点的数据
	BinaryTreeNode<T>*  leftchild() const;    //返左孩子指针
	BinaryTreeNode<T>*  rightchild() const; //返右孩子指针
	void setLeftchild(BinaryTreeNode<T>* l)const ;
	 //设置当前结点的左子树
	void setRightchild(BinaryTreeNode<T>* r)const ;
	//设置当前结点的右子树
	void  setValue(const T& val);
	//设置当前结点的数据域
	bool  isLeaf() const; 
    //判定当前结点是否为叶结点,若是返回true
	BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node);
	 //重载赋值操作符=
};

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(){
	info = 0;
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
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* l)const{
	left = l;
}

template <class T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* r)const{
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

int main(int argc, char const *argv[])
{
	int x = 10;
	BinaryTreeNode<int> A(1);
	x = A.isLeaf();
	cout << x << endl;

	return 0;
}