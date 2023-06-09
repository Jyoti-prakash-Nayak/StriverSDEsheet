#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:g){
        int u=it.first.first;
        int v=it.first.second;
        int w=it.second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push({{0,1},-1});
    vector<int>vis(n+1,0);
    vector<pair<pair<int,int>,int>>res;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int wt=it.first.first;
        int node=it.first.second;
        int parent=it.second;

        if(vis[node]==1)
          continue;

        vis[node]=1;
        if(parent!=-1){
            res.push_back({{parent,node},wt});
        }

        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgwt=it.second;
            if(!vis[adjNode]){
                pq.push({{edgwt,adjNode},node});
            }
        }
    }
    
    return res;




}
