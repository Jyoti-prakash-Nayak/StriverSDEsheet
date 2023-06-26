#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* f(int start,int end,vector<int>&arr){
    if(start>=end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode<int>*root=new TreeNode<int>(arr[mid]);
    root->left=f(start,mid,arr);
    root->right=f(mid+1,end,arr);

    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return f(0,n,arr);
}