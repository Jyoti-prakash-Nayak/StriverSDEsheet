#include <bits/stdc++.h>
bool isSafe(int row, int col, int n, vector<vector<int>> &temp)
{
    int dupRow = row;
    int dupCol = col;
    while (row >= 0 && col >= 0)
    {
        if (temp[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while (col >= 0)
    {
        if (temp[row][col] == 1)
            return false;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while (row < n && col >= 0)
    {
        if (temp[row][col] == 1)
            return false;
        row++;
        col--;
    }

    return true;
}
void f(int col, int n, vector<vector<int>> &temp, vector<vector<int>> &res)
{
    if (col == n)
    {
        vector<int> v;
        for (auto it : temp)
        {
            for (int i = 0; i < it.size(); i++)
            {
                v.push_back(it[i]);
            }
        }
        res.push_back(v);
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, temp))
        {
            temp[row][col] = 1;
            f(col + 1, n, temp, res);
            temp[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> temp(n, vector<int>(n, 0));
    vector<vector<int>> res;
    f(0, n, temp, res);
    return res;
}