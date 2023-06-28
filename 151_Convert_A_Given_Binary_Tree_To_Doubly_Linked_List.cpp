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
void solve(BinaryTreeNode<int>*root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>*&prev,int &f){
    if(root==NULL)
      return;
    solve(root->left,head,prev,f);
    if(f==0){
        f=1;
        head=root;
        prev=root;
    }
    else{
        prev->right=root;
        prev->right->left=prev;
        prev=prev->right;
    }
    solve(root->right,head,prev,f);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* prev=NULL;
    BinaryTreeNode<int>* head=NULL;
    int f=0;
    solve(root,head,prev,f);
    return head;
}