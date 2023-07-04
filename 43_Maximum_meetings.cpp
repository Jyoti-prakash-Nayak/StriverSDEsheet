#include <bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < start.size(); i++)
    {
        v.push_back({end[i], {i + 1, start[i]}});
    }

    vector<int> res;
    sort(v.begin(), v.end());
    int finish = v[0].first;
    res.push_back(v[0].second.first);

    for (int i = 1; i < start.size(); i++)
    {
        if (v[i].second.second > finish)
        {
            finish = v[i].first;
            res.push_back(v[i].second.first);
        }
    }
    return res;
}