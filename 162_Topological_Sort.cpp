#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }

    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++){
       if(indegree[i]==0){
           q.push(i);
       }
    }

    vector<int>res;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return res;
}