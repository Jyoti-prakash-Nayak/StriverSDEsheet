#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    // Write your code here.
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({a[i] + b[n - 1], {i, n - 1}});
    }

    vector<int> res;
    while (!pq.empty() && k--)
    {
        int val = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();
        res.push_back(val);
        pq.push({a[x] + b[y - 1], {x, y - 1}});
    }
    return res;
}