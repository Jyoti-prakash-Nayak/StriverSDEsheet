#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool f(TreeNode<int> *root, int x,vector<int>&res){
	if(root==NULL)
	   return false;
	res.push_back(root->data);

	if(root->data==x){
		return true;
	}
	if(f(root->left,x,res)||f(root->right,x,res)){
		return true;
	}
	res.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.

	vector<int>res;
	if(root==NULL){
		return res;
	}
	f(root,x,res);
	return res;
}
