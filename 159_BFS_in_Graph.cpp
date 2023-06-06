#include <bits/stdc++.h> 
void bfs(int node,unordered_map<int,set<int>> &adj,vector<int>&vis,vector<int>&res){
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
       auto curr=q.front();
       q.pop();
       res.push_back(curr);
       for(auto it:adj[curr]){
           if(!vis[it]){
               q.push(it);
               vis[it]=1;
           }
       }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,set<int>>adj;
    for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].insert(v);
    adj[v].insert(u);
    }

    vector<int>res;
    vector<int>vis(vertex,0);
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            bfs(i,adj,vis,res);
        }
    }
    return res;
}