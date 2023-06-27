#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void f(TreeNode<int>* root,vector<int>&res){
     if(root==NULL)
        return;
    f(root->left,res);
    res.push_back(root->data);
    f(root->right,res);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    vector<int>res;
    f(root,res);
    int n=res.size();
    
    return res[k-1];
}