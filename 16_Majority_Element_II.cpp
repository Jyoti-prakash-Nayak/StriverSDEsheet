#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>mp;
    for(auto it:arr){
        mp[it]++;
    }
     vector<int>res;
    for(auto it:mp){
        if(it.second > arr.size()/3){
            res.push_back(it.first);
        }
    }
    return res;
}