#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void f(BinaryTreeNode<int>* root,vector<int>&inorder){
    if(root==NULL)
      return;
    f(root->left,inorder);
    inorder.push_back(root->data);
    f(root->right,inorder);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int,int>ans(-1,-1);
    vector<int>inorder;
    if(root==NULL)
      return ans;
    f(root,inorder);
    
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==key){
            if(i-1>=0)
               ans.first=inorder[i-1];
            if(i+1<inorder.size())
               ans.second=inorder[i+1];
        }
    }
    return ans;
}
