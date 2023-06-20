#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long left[n]={0};
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    long right[n]={0};
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
      right[i]=max(right[i+1],arr[i]);
    }

    long ans=0;
    for(int i=1;i<n-1;i++){
        ans +=min(left[i],right[i])-arr[i];
    }
    return ans;
}