#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void f(BinaryTreeNode<int> *root, vector<int> &res){
     if(root==NULL)
       return;
     f(root->left,res);
     res.push_back(root->data);
     f(root->right,res);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
   vector<int>res;
   f(root,res);
   int i=0;
   int j=res.size()-1;

   while(i<j){
       if(res[i]+res[j]==k)
         return true;
        else if(res[i]+res[j]<k)
           i++;
        else
         j--;
   }
   return false;
}