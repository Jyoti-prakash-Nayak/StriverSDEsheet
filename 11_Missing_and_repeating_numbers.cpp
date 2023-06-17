#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++){
       mp[arr[i]]++;
	}
    
	int a,b;
	for(int i=1;i<=n;i++){
		if(mp[i]==0){
			a=i;
		}
		if(mp[i]>1){
			b=i;
		}
	}

   return {a,b};
}
