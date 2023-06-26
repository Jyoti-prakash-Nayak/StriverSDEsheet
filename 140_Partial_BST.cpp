#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
bool f(BinaryTreeNode<int> *root,BinaryTreeNode<int> *mini,BinaryTreeNode<int> *maxi){
    if(root==NULL)
      return true;
    if(mini && root->data < mini->data  || maxi && root->data > maxi->data)
      return false;
    return f(root->left,mini,root)&&f(root->right,root,maxi);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return f(root,NULL,NULL);
}