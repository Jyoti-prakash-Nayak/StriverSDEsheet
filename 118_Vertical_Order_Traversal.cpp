#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>res;
    map<int,map<int,vector<int>>> mp;
    queue<pair<TreeNode<int> *,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
       auto it=q.front();
       q.pop();
    
       TreeNode<int> *node=it.first;
       int x=it.second.first;
       int y=it.second.second;

       mp[x][y].push_back(node->data);
       if(node->left)
         q.push({node->left,{x-1,y+1}});
       if(node->right)
         q.push({node->right,{x+1,y+1}});   
    }

    for(auto i:mp){
        for(auto j:i.second){
            for(auto k:j.second){
                res.push_back(k);
            }
        }
    }
    return res;

}