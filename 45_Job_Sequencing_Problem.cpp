#include <bits/stdc++.h>
bool com(vector<int> j1, vector<int> j2)
{
    return j1[1] > j2[1] || (j1[1] == j2[1] && j1[0] >= j2[0]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), com);
    int maxi = -1, profit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxi = max(maxi, jobs[i][0]);
    }
    vector<int> dp(maxi + 1, -1);
    for (int i = 0; i < jobs.size(); i++)
    {
        int d = jobs[i][0];
        for (int j = d; j > 0; j--)
        {
            if (dp[j] == -1)
            {
                dp[j] = jobs[i][1];
                break;
            }
        }
    }
    for (int i = 1; i <= maxi; i++)
    {
        if (dp[i] != -1)
        {
            profit += dp[i];
        }
    }
    return profit;
}