#include <bits/stdc++.h>
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    int n = start.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], finish[i]});
    }
    sort(v.begin(), v.end(), cmp);
    int end = v[0].second;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= end)
        {
            count++;
            end = v[i].second;
        }
    }
    return count;
}