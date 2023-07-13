#include <bits/stdc++.h>
int DR[4] = {1, 0, -1, 0};
int DC[4] = {0, 1, 0, -1};
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // Write your code here.
    int vis[n][m];
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    while (!q.empty())
    {
        int t = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        tm = max(tm, t);

        for (int k = 0; k < 4; k++)
        {
            int newx = x + DR[k];
            int newy = y + DC[k];

            if (newx >= 0 && newx < n && newy >= 0 && newy < m && vis[newx][newy] != 2 && grid[newx][newy] == 1)
            {
                q.push({t + 1, {newx, newy}});
                vis[newx][newy] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 && grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return tm;
}