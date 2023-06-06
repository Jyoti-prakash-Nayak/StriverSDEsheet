
void dfs(int node,vector<vector<int>> &adj,vector<int> &temp,vector<int> &vis){
    // if(vis[node])
    //   return;
    vis[node]=1;
    temp.push_back(node);

    for(int it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,temp,vis);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
     vector<vector<int>> res;
     vector<int> vis(V,0);

     for(int i=0;i<V;i++){
         if(!vis[i]){
             vector<int>temp;
             dfs(i,adj,temp,vis);
             res.push_back(temp);
         }
     }
     return res;
}