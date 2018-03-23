template <class T>
class BinaryTree { // C++定义, 没有具体规定存储方式
  private:
	 BinaryTreeNode<T>*  root; //二叉树根结点指针
  public:
  BinaryTree( ){ root=NULL;} 	   //构造函数
  ~BinaryTree( ) {DeleteBinaryTree(root);}//析构函数
  bool isEmpty() const;     	   //判二叉树是否为空树
  BinaryTreeNode<T>* Root(){return root;}//返二叉树根
  BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* 				  current);       //返回current结点的父结点
