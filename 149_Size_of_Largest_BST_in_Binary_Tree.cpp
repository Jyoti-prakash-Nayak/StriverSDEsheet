#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class info{
    
    public:
    int mini;
    int maxi;
    int size;
    bool isBST;
    
    info(){
        
    }
    info(int a, int b, int c, bool d){
        mini = a;
        maxi = b;
        size = c;
        isBST = d;
    }
};

info f(TreeNode<int>* root, int &ans){
    if(root==NULL)
       return info{INT_MAX,INT_MIN,0,true};
    
    info leftAns=f(root->left,ans);
    info rightAns=f(root->right,ans);

    info curr;

    curr.size=leftAns.size+rightAns.size+1;
     curr.mini = min(leftAns.mini, root->data);
    curr.maxi = max(rightAns.maxi, root->data);

      if(leftAns.isBST && rightAns.isBST && (root->data > leftAns.maxi && root->data < rightAns.mini)){
        curr.isBST = true;
    }
    else{
        curr.isBST = false;
    }
    
    if(curr.isBST){
        ans = max(ans, curr.size);
    }
    return curr;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
     int ans=0;
     info temp=f(root,ans);
     return ans;
}
