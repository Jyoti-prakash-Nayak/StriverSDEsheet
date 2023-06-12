int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>dp(n+1);
	dp[0]=0,dp[1]=price[0];
	for(int i=2;i<=n;i++) {
		for(int j=0;j<i;j++) {
			dp[i]=max(price[i-j-1]+dp[j],dp[i]);
		}
	}
	return dp[n];
}
