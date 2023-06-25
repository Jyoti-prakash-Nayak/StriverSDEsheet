#include <bits/stdc++.h> 
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* f(vector<int>& inOrder,int inStart,int inEnd,vector<int>& postOrder,int poStart,int poEnd, map<int,int> &mp){
     if(inStart > inEnd || poStart > poEnd)
        return NULL;
     
     TreeNode<int>*node=new TreeNode<int>(postOrder[poEnd]);
     int inRoot=mp[node->data];
     int len=inRoot-inStart;

     node->left=f(inOrder,inStart,inRoot-1,postOrder,poStart,poStart+len-1,mp);
     node->right=f(inOrder,inRoot+1,inEnd,postOrder,poStart+len,poEnd-1,mp);

     return node;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int n=inOrder.size();
     int m=postOrder.size();
     map<int,int>mp;
     for(int i=0;i<n;i++){
          mp[inOrder[i]]=i;
     }
     return f(inOrder,0,n-1,postOrder,0,m-1,mp);
}
