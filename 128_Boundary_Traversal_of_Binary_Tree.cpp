#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void traverseLeft(TreeNode<int>* root, vector<int> &res){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    res.push_back(root->data);
    if(root->left)
      traverseLeft(root->left,res);
    else
      traverseLeft(root->right,res);
}
void traversLeaf(TreeNode<int>* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
       res.push_back(root->data);
       return;
    }
    
      traversLeaf(root->left,res);
      traversLeaf(root->right,res);
}
void traversRight(TreeNode<int>* root, vector<int> &res){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
   
    if(root->right)
     traversRight(root->right,res);
    else
      traversRight(root->left,res);
    res.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res;
    if(root==NULL)
      return res;
    res.push_back(root->data);

    traverseLeft(root->left,res);

    traversLeaf(root->left,res);
    traversLeaf(root->right,res);

    traversRight(root->right,res);

    return res;
}