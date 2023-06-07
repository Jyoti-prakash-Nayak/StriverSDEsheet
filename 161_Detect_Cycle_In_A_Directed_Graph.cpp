#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>> &adj,vector<int>& vis,vector<int>& dfsvis)
{
  vis[node]=1;
  dfsvis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      if(dfs(it,adj,vis,dfsvis))
        return true;
    }
    else if(dfsvis[it]){
      return true;
    }
  }
  dfsvis[node]=0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   vector<vector<int>> adj(n+1);
   for(int i=0;i<edges.size();i++){
     adj[edges[i].first].push_back(edges[i].second);
   }
   
   vector<int>vis(n+1,0);
   vector<int> dfsVis(n+1,0);
   for(int i=1;i<=n;i++){
     if(!vis[i]){
       if(dfs(i,adj,vis,dfsVis))
         return true;
     }
   }
   return false;
}