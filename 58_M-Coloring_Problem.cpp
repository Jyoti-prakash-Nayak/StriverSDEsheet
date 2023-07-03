#include <bits/stdc++.h>
bool isValid(int i, int node, vector<vector<int>> &mat, vector<int> &col)
{
    for (int j = 0; j < mat.size(); j++)
    {
        if (mat[node][j] == 1 && col[j] == i)
            return false;
    }
    return true;
}
bool f(int node, int m, vector<vector<int>> &mat, vector<int> &col, int n)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isValid(i, node, mat, col))
        {
            col[node] = i;
            if (f(node + 1, m, mat, col, n))
                return true;
            col[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> col(n, 0);
    if (f(0, m, mat, col, n))
        return "YES";
    return "NO";
}