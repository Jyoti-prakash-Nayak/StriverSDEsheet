#include <bits/stdc++.h> 
class Disjoint{
	public:
	vector<int>parent,size;
	Disjoint(int n){
		parent.resize(n+1);
		size.resize(n+1,1);
		for(int i=1;i<=n;i++){
			parent[i]=i;
		}
	}
	int find(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=find(parent[node]);
	}
	void unionBySize(int u,int v){
		int pu=find(u);
		int pv=find(v);

		if(size[pu]<size[pv]){
			parent[pu]=pv;
			size[pv] +=size[pv];

		}
		else{
			parent[pv]=pu;
			size[pu] +=size[pv];
		}
	}
};
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    vector<pair<int,pair<int,int>>>edges;
	for(auto it:graph){
		int u=it[0];
		int v=it[1];
		int wt=it[2];

		edges.push_back({wt,{u,v}});
		edges.push_back({wt,{v,u}});
	}

	sort(edges.begin(),edges.end());

	Disjoint st(n);
	int sum=0;

	for(auto it:edges){
		int wt=it.first;
		int u=it.second.first;
		int v=it.second.second;

		if(st.find(u)!=st.find(v)){
			sum +=wt;
			st.unionBySize(u,v);
		}
	}

    return sum;

}