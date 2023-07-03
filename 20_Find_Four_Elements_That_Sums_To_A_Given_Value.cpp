#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    unordered_map<long long, pair<int, int>> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long sum = arr[i] + arr[j];
            long long k = target - sum;
            if (mp.find(k) != mp.end())
            {
                if (mp[k].first != i && mp[k].second != j)
                {
                    return "Yes";
                }
            }
            mp[sum] = {i, j};
        }
    }
    return "No";
}
