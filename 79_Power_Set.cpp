#include <bits/stdc++.h>
void f(int ind, vector<int> &v, vector<int> &temp, vector<vector<int>> &res)
{
    res.push_back(temp);
    for (int i = ind; i < v.size(); i++)
    {
        temp.push_back(v[i]);
        f(i + 1, v, temp, res);
        temp.pop_back();
    }
}
vector<vector<int>> pwset(vector<int> v)
{
    // Write your code here
    vector<vector<int>> res;
    vector<int> temp;
    f(0, v, temp, res);
    return res;
}