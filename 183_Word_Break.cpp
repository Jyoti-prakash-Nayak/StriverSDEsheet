#include <bits/stdc++.h> 
bool f(int ind,string &T,set<string>&st, vector<int> &dp){
    if(ind==T.size())
       return true;
    if(dp[ind]!=-1)
       return dp[ind];
    string temp="";
    for(int i=ind;i<T.size();i++){
         temp +=T[i];
         if(st.find(temp)!=st.end()){
             if(f(i+1,T,st,dp)){
                 return dp[ind]=true;
             }
         }
    }
    return dp[ind]=false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    set<string>st;
    for(auto it:arr){
        st.insert(it);
    }
    vector<int>dp(target.size(),-1);
    return f(0,target,st,dp);
}