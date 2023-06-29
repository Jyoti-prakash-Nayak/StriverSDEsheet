#include <bits/stdc++.h>
void f(int ind, int sum, vector<int> &num, int n, vector<int> &res)
{
    if (ind == n)
    {
        res.push_back(sum);
        return;
    }
    f(ind + 1, sum + num[ind], num, n, res);
    f(ind + 1, sum, num, n, res);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> res;
    int n = num.size();
    f(0, 0, num, n, res);
    return res;
}