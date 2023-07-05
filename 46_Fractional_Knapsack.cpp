#include <bits/stdc++.h>
bool cmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &item, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(item.begin(), item.end(), cmp);
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        if (item[i].first <= w)
        {
            res += item[i].second;
            w -= item[i].first;
        }
        else
        {
            res += (item[i].second * ((double)w / item[i].first));
            break;
        }
    }
    return res;
}