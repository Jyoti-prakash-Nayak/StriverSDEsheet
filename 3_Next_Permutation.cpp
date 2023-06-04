#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
        
         int i=n-2;
        while(i>=0 && permutation[i+1]<=permutation[i]){
            i--;
        }
        if(i>=0){
            int j=n-1;
            while(permutation[j]<=permutation[i])
            {
                j--;
            }
            swap(permutation[i],permutation[j]);
        }
        reverse(permutation.begin()+i+1,permutation.end());
        vector<int> res(permutation.begin(),permutation.end());
    return res;
}