#include <iostream>
#include "lnkStack.h"
#include "BinaryTree.h"
using namespace std;
template <class T>
BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* root,BinaryTreeNode<T>* current){
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

		if (pointer -> leftchild() == current || pointer ->rightchild() == current)
		{return pointer;}
		else
			{
			if (pointer -> rightchild() != NULL)
				aStack.push(pointer->rightchild());
			if (pointer -> leftchild() != NULL)
				pointer = pointer -> leftchild();
			else{
				aStack.pop(x);
				pointer = x;
				}
			}
	}
	return root;
}


template <class T>
bool Search(BinaryTreeNode<T>* root , T k){
	bool r = 0;
	bool l = 0;
	if (root -> value() == k)	return 1;
	else{
		if (root -> rightchild()){
			r = Search(root -> rightchild(), k);
		}
		if (root -> leftchild()){
			l = Search(root -> leftchild(), k);
		}
		return (r||l);
	}
}

template <class T>
BinaryTreeNode<T> * CommonAncestor (BinaryTreeNode<T> * root, BinaryTreeNode<T> * p, BinaryTreeNode<T> * q) {
	BinaryTreeNode<T>* pointer = p;
	while(1){
		if (Search(pointer, q->value()))
		{
			return pointer;
		}
		pointer = Parent(root,pointer);
	}
};


int main()
{
	BinaryTreeNode<string> a,b,c,d,e,f,g,h;
	a.setValue("a");
	b.setValue("b");
	c.setValue("c");
	d.setValue("d");
	e.setValue("e");
	f.setValue("f");
	g.setValue("g");
	h.setValue("h");
	BinaryTree<string> T2;
	T2.CreateTree(a,b,c);
	c.setRightchild(&d);
	c.setLeftchild(&f);
	b.setLeftchild(&e);
	b.setRightchild(&g);
	g.setLeftchild(&h);
	// cout << T2.Parent(&d) << endl;
	T2.print();
	cout << CommonAncestor(&a,&e,&h)->value();
	return 0;
}
