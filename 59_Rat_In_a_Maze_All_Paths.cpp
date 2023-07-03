#include <bits/stdc++.h>
int DR[4] = {1, 0, -1, 0};
int DC[4] = {0, 1, 0, -1};
void f(int r, int c, int n, vector<int> &temp, vector<vector<int>> &vis, vector<vector<int>> &res, vector<vector<int>> &maze)
{
    if (r == n - 1 && c == n - 1)
    {
        res.push_back(temp);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int newR = r + DR[k];
        int newC = c + DC[k];

        if (newR >= 0 && newR < n && newC >= 0 && newC < n && maze[newR][newC] == 1 && vis[newR][newC] != 1)
        {
            vis[newR][newC] = 1;
            temp[n * newR + newC] = 1;
            f(newR, newC, n, temp, vis, res, maze);
            vis[newR][newC] = 0;
            temp[n * newR + newC] = 0;
        }
    }
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<vector<int>> res;
    vector<int> temp(n * n, 0);

    vis[0][0] = 1;
    temp[0] = 1;
    f(0, 0, n, temp, vis, res, maze);

    return res;
}