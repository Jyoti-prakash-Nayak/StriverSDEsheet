#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int col,vector<int> &color,vector<vector<int>> &adj){
    
	color[node]=col;
	for(auto it:adj[node]){
		if(color[it]==-1){
			if(dfs(it,!col,color,adj)==false){
                  return false;
			}
		}
		else if(color[it]==col){
			return false;
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<vector<int>>adj(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<edges[0].size();j++){
			if(edges[i][j]){
               adj[i].push_back(j);
			   adj[j].push_back(i);
			}
		}
	}
	vector<int> color(n,-1);
	for(int i=0;i<n;i++){
        if (color[i] == -1) {
            if (dfs(i,0, color, adj) == false)
              return false;
          }
        }
	return true;
}