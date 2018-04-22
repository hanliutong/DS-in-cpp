#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

TreeNode* Parent(TreeNode* root,TreeNode* current){
	stack<TreeNode*> aStack;
	TreeNode* pointer = root;
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
				pointer = aStack.top();
                aStack.pop();
				}
			}
	}
	return root;
}

bool Search(TreeNode* root ,  TreeNode* tar){
	bool r = 0;
	bool l = 0;
	if (root  == tar)	return 1;
	else{
		if (root -> right){
			r = Search(root -> right, tar);
		}
		if (root -> left){
			l = Search(root -> left, tar);
		}
		return (r||l);
	}
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* pointer = p;
	while(1){
		if (Search(pointer, q))
			return pointer;
		pointer = Parent(root,pointer);
	}
}
    
};


int main()
{

	return 0;
}
