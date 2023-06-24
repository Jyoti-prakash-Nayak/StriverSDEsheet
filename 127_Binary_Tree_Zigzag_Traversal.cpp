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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>res;
    if(root==NULL)
      return res;
    bool flag=true;
   
    stack<BinaryTreeNode<int> *>st;
    queue<BinaryTreeNode<int> *>q;
     q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto node=q.front();
            q.pop();
            res.push_back(node->data);
            if(flag){
                if(node->left)
                  st.push(node->left);
                if(node->right)
                  st.push(node->right);
            }
            else{
                if(node->right)
                  st.push(node->right);
                if(node->left)
                  st.push(node->left);
            }
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
           
        }
        flag =!flag;
    }
    return res;
}
