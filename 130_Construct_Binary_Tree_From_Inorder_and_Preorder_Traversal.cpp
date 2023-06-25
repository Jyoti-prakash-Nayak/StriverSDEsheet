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
TreeNode<int> *f(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &mp){
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }
    
    TreeNode<int> *node=new TreeNode<int>(preorder[preStart]);
    int nRoot=mp[node->data];
    int len=nRoot-inStart;
    
    node->left=f(preorder,preStart+1,preStart+len,inorder,inStart,nRoot-1,mp);
    node->right=f(preorder,preStart+len+1,preEnd,inorder,nRoot+1,inEnd,mp);
   
    return node;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n=inorder.size();
    int m=preorder.size();
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }

    return f(preorder,0,m-1,inorder,0,n-1,mp);

}