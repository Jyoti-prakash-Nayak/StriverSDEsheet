#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    priority_queue<pair<int, int>> pq;
    vector<int> res;
    unordered_map<int, int> mp;

    for (auto it : arr)
    {
        mp[it]++;
    }

    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }

    for (int i = 1; i <= k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    return res;
}