#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
     if(!root)
        return "";
     string str="";
     queue<TreeNode<int> *>q;
     q.push(root);

     while(!q.empty()){
         TreeNode<int> * curr=q.front();
         q.pop();

         if(curr==NULL){
             str.append("#,");
         }
         else{
             str.append(to_string(curr->data)+',');
             q.push(curr->left);
             q.push(curr->right);
         }
     }
    return str;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size()==0)
      return NULL;
    stringstream ss(serialized);
    string str;
    getline(ss,str,',');
    TreeNode<int>*root=new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* curr=q.front();
        q.pop();

        getline(ss,str,',');
        if(str=="#"){
            curr->left=NULL;
        }
        else{
            TreeNode<int>* leftNode=new TreeNode<int>(stoi(str));
            curr->left=leftNode;
            q.push(leftNode);
        }


        getline(ss,str,',');
        if(str=="#"){
            curr->right=NULL;
        }
        else{
            TreeNode<int>* rightNode=new TreeNode<int>(stoi(str));
            curr->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;

}



