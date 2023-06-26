#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>*f(int &ind,int bound,vector<int> &preOrder){
    if(ind==preOrder.size() || preOrder[ind]>bound)
      return NULL;
    TreeNode<int>*root=new TreeNode<int>(preOrder[ind++]);
    root->left=f(ind,root->data,preOrder);
    root->right=f(ind,bound,preOrder);
    
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return f(i,INT_MAX,preOrder);
}