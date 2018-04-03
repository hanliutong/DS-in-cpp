#ifndef _TREENODE_H
#define _TREENODE_H
template <class T>
class Tree;
template <class T>
class TreeNode{
friend class Tree<T>;
private: 
	TreeNode<T>* pChild;
	TreeNode<T>* pSibling;
	T m_Value;
public:
	TreeNode(){pChild = pSibling = NULL;};
	TreeNode(const T& value);
	~TreeNode(){};
	void setValue(const T& value);
	void setClild(TreeNode* pointer);
	void setSibling(TreeNode* pointer);
};

template<class T>
TreeNode<T>::TreeNode(const T& value){
	m_Value = value;
	pChild = pSibling = NULL;
}

template <class T>
void TreeNode<T>::setValue(const T& value){
	m_Value = value;
}


template <class T>
void TreeNode<T>::setClild(TreeNode* pointer){
	pChild = pointer;
}

template <class T>
void TreeNode<T>::setSibling(TreeNode* pointer){
	pSibling = pointer;
}
#endif //_TREENODE_H