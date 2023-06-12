#include<bits/stdc++.h>
long f(int ind,int T,int *arr, vector<vector<long>> &dp){
    if(ind==0){
        return (T%arr[0]==0);
    }
    if(dp[ind][T]!=-1)
      return dp[ind][T];
    long notTake=f(ind-1,T,arr,dp);
    long take=0;
    if(arr[ind]<=T){
        take=f(ind,T-arr[ind],arr,dp);
    }
    return dp[ind][T]=(take+notTake);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
}