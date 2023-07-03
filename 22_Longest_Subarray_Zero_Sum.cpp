#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    unordered_map<int, int> mp;
    int n = arr.size();
    int maxi = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
        if (ans == 0)
        {
            maxi = i + 1;
        }
        else if (mp.find(ans) != mp.end())
        {
            maxi = max(maxi, i - mp[ans]);
        }
        else
        {
            mp[ans] = i;
        }
    }
    return maxi;
}