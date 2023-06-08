#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}
void dfs2(int node,vector<int>&vis,vector<int>&temp,vector<int>adjT[]){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adjT[node]){
        if(!vis[it]){
            dfs2(it,vis,temp,adjT);
        }
    }
    
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }

    vector<int> vis(n,0);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    vector<int> adjT[n];//reverse the adjList
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            adjT[it].push_back(i);
        }
    }

    vector<vector<int>> res;
    while(!st.empty()){
       auto node=st.top();
       st.pop();
       vector<int> temp;
        if(!vis[node]){
            dfs2(node,vis,temp,adjT);
        }
       
       res.push_back(temp);
    }
   return res;
}
