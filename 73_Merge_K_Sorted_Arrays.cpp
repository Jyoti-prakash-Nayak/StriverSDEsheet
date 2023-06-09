#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for (auto it : kArrays)
    {
        for (auto x : it)
        {
            pq.push(x);
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
