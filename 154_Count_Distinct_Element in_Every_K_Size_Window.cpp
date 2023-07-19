#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    vector<int> res;
    int i = 0;
    int j = 0;
    unordered_map<int, int> mp;
    while (j < arr.size())
    {
        if (j - i + 1 < k)
        {
            mp[arr[j]]++;
            j++;
        }
        else if (j - i + 1 == k)
        {
            mp[arr[j]]++;

            res.push_back(mp.size());
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
            {
                mp.erase(arr[i]);
            }

            i++;
            j++;
        }
    }
    return res;
}
