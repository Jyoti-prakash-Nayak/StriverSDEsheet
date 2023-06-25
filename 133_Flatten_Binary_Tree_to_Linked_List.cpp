#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
void f(TreeNode<int> *root,TreeNode<int> *&prev){
    if(root==NULL)
      return;
    f(root->right,prev);
    f(root->left,prev);

    root->right=prev;
    root->left=NULL;
    prev=root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *prev=NULL;
    f(root,prev);
    return root;
}