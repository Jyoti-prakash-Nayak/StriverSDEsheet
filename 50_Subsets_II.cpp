#include <bits/stdc++.h>
void f(int ind, vector<int> &arr, vector<vector<int>> &res, vector<int> &temp)
{
    res.push_back(temp);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i == ind || arr[i] != arr[i - 1])
        {
            temp.push_back(arr[i]);
            f(i + 1, arr, res, temp);
            temp.pop_back();
        }
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    f(0, arr, res, temp);
    return res;
}