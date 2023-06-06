#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
unordered_map<graphNode*,graphNode*>mp;
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(node==NULL)
	  return NULL;
	
	graphNode* first=new graphNode(node->data,{});
	mp[node]=first;
	queue<graphNode*>q;
	q.push(node);

	while(!q.empty()){
		graphNode* curr=q.front();
		q.pop();

		for(auto it:curr->neighbours){
			if(mp.find(it)==mp.end()){
               mp[it]=new graphNode(it->data,{});
			   q.push(it);
			}
			mp[curr]->neighbours.push_back(mp[it]);
		}
	}
    return mp[node];

}