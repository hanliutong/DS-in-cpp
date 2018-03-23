#include "arrStack.h"
#include "BinaryTreeNode.h"
#include <iostream>
using std::cout;

template <class T>
class BinaryTree { // C++定义, 没有具体规定存储方式
private:
	BinaryTreeNode<T>*  root; //二叉树根结点指针
public:
	BinaryTree( ){ root=NULL;} 	   //构造函数
	//~BinaryTree( ) {DeleteBinaryTree(root);}//析构函数
	~BinaryTree( ){};
	bool isEmpty() const;     	   //判二叉树是否为空树
	BinaryTreeNode<T>* Root(){return root;}//返二叉树根
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);//返回current结点的父结点
	BinaryTreeNode<T>* LeftSibling(
	BinaryTreeNode<T>* current); //返current结点左兄弟
	BinaryTreeNode<T>* RightSibling(
    BinaryTreeNode<T>* current); //返current右兄弟
	void CreateTree(const T& elem, BinaryTree<T>& 
                     leftTree, 	BinaryTree<T>& rightTree);
               // 已知根、左子树、右子树，构造二叉树
	void PreOrder(BinaryTreeNode<T>* root); //前序周游bt
	void InOrder(BinaryTreeNode<T>* root); //中序周游
	void PostOrder(BinaryTreeNode<T>* root); //后序周游
	void LevelOrder(BinaryTreeNode<T>* root); //按层次周游
	void DeleteBinaryTree(BinaryTreeNode<T>* root);//删bt
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
	arrStack<BinaryTreeNode<T>*> aStack;
	BinaryTreeNode<T>* pointer = root;
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
	arrStack<BinaryTreeNode<T>*> aStack;
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

template <class T>
void BinaryTree<T>::CreateTree(const T& elem, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree){

}

int main(int argc, char const *argv[])
{
	BinaryTree<int> T1;
	return 0;
}