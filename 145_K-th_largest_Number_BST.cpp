#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
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
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int>res;
    f(root,res);
    int n=res.size();
    if(n<k){
        return -1;
    }
    return res[n-k];

}
