#include<bits/stdc++.h>

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(w+1,0));
	for(int i=weights[0];i<=w;i++){
		dp[0][i]=values[0];
	}
	
	for(int ind=1;ind<n;ind++){
		for(int cap=0;cap<=w;cap++){
			int notTake=dp[ind-1][cap];
	        int take=INT_MIN;
	        if(weights[ind]<=cap){
	        	take=values[ind]+dp[ind-1][cap-weights[ind]];
	        }
             dp[ind][cap]=max(take,notTake);
		}
	}
	return dp[n-1][w];
}