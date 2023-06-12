#include <bits/stdc++.h> 
bool f(int ind,int T,vector<int>&arr, vector<vector<int>> &dp){
    if(T==0)
       return true;
    if(ind==0)
      return (arr[0]==T);
    if(dp[ind][T]!=-1)
       return dp[ind][T];
    bool notTake=f(ind-1,T,arr,dp);
    bool take=false;
    if(arr[ind]<=T){
        take=f(ind-1,T-arr[ind],arr,dp);
    }
    return dp[ind][T]=take|notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}