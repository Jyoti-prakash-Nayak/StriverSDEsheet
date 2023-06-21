#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void solve(BinaryTreeNode<int> *root, vector<vector<int>>&res){
    if(root==NULL)
      return;
    res[1].push_back(root->data);
    solve(root->left,res);
    res[0].push_back(root->data);
    solve(root->right,res);
    res[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>res(3);
    solve(root,res);
    return res;
}