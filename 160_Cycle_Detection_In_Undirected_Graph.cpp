#include<bits/stdc++.h>
using namespace std;
bool bfsCheck(vector<int> adjList[], vector<int> &visited, int i, int v)
{
	vector<int> parent(v+1, -1);
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		for(auto n: adjList[front])
		{
			if(!visited[n])
			{
				visited[n] = true;
				q.push(n);
				parent[n] = front;
			}
			else if(visited[n]==true && n != parent[front])
			{
				return true;
			}
		}
	}
	return false;
}

string cycleDetection (vector<vector<int>>& edges, int v, int m)
{
    // Write your code here.
    vector<int> adjList[v+1];
    for(int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> visited(v+1, 0);

	for(int i = 0; i < v; i++)
    {
        if(!visited[i])
            if(bfsCheck(adjList, visited, i, v))
				return "Yes";
    }

    return "No";
}
