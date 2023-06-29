#include <bits/stdc++.h>
void f(int ind, int k, vector<int> &arr, vector<vector<int>> &res, vector<int> &temp)
{
    if (ind == arr.size())
    {
        if (k == 0)
        {
            res.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[ind]);
    f(ind + 1, k - arr[ind], arr, res, temp);
    temp.pop_back();
    f(ind + 1, k, arr, res, temp);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> temp;

    f(0, k, arr, res, temp);
    return res;
}